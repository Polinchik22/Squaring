#include "testing_solving.h"

double Starting_Test(){
    printf("Хотите ли вы протестировать программу? [Y/N] ");
    if (getchar() == 'Y'){
        printf("\n" "Хорошо! Запускаю тестирование... \n");

        Running_All_Hand_Tests();
        Running_generated_tests(AMOUNT_GENERATED_TESTS);
    } else {
        printf("\n" "Не беда! Пиши мне если надо будет решить квадратное уравнения!"
                "Я всегда помогу!");
    }

    return 0;
}


double Running_All_Hand_Tests() {
    int correct_ref_tests = 0;

    const Equation Ref_Book[AMOUNT_REF_TESTS] = {
        {{.coef_2 = 1, .coef_1 = -5, .coef_0 =   6}, .solution_1 =  3  , .solution_2 =  2  , .amount_solution = TWO_SOLUTIONS     },
        {{.coef_2 = 1, .coef_1 =  0, .coef_0 =  -1}, .solution_1 =  1  , .solution_2 = -1  , .amount_solution = TWO_SOLUTIONS     },
        {{.coef_2 = 1, .coef_1 = -1, .coef_0 =   0}, .solution_1 =  1  , .solution_2 =  0  , .amount_solution = TWO_SOLUTIONS     },
        {{.coef_2 = 1, .coef_1 =  2, .coef_0 =   1}, .solution_1 = -1  , .solution_2 =  NAN, .amount_solution = ONE_SOLUTION      },
        {{.coef_2 = 0, .coef_1 =  1, .coef_0 =  -1}, .solution_1 =  1  , .solution_2 =  NAN, .amount_solution = ONE_SOLUTION      },
        {{.coef_2 = 1, .coef_1 =  0, .coef_0 =   0}, .solution_1 =  0  , .solution_2 =  NAN, .amount_solution = ONE_SOLUTION      },
        {{.coef_2 = 1, .coef_1 =  0, .coef_0 =   1}, .solution_1 =  NAN, .solution_2 =  NAN, .amount_solution = NO_SOLUTIONS      },
        {{.coef_2 = 1, .coef_1 =  1, .coef_0 =  23}, .solution_1 =  NAN, .solution_2 =  NAN, .amount_solution = NO_SOLUTIONS      },
        {{.coef_2 = 0, .coef_1 =  0, .coef_0 =   0}, .solution_1 =  NAN, .solution_2 =  NAN, .amount_solution = INFINITY_SOLUTIONS},
    };

    for (int i = 0; i < AMOUNT_REF_TESTS; i++){
        correct_ref_tests += Running_Hand_Test(Ref_Book[i]);
    }

    double hand_tests_accuracy = correct_ref_tests / AMOUNT_REF_TESTS;

    printf("\n Верных ручных проверок %d из %d \n", correct_ref_tests, AMOUNT_REF_TESTS);

    return hand_tests_accuracy;
}


bool Running_Hand_Test(const Equation Ref_Equation){
    //не ебу, каж не нужны асерты

    Equation Prog_Equation = {Ref_Equation.coefficients,
                              .solution_1      = NAN,
                              .solution_2      = NAN,
                              .amount_solution = INITIALIZATION};

    solving_equation(&Prog_Equation);

    if  (Ref_Equation.amount_solution != Prog_Equation.amount_solution    ||
            !is_equal(Ref_Equation.solution_1, Prog_Equation.solution_1 ) ||
            !is_equal(Ref_Equation.solution_2, Prog_Equation.solution_2)) {

        printing_error_with_ref(Ref_Equation, Prog_Equation);
        return false;
        }

    return true;
}


double Running_generated_tests(int amount_generated_tests){
    int correct_generated_tests = 0;

    for (int test_numb = 0; test_numb < amount_generated_tests; test_numb++){
        Equation Generated_Equation = {{frand(), frand(), frand()},
                                    .solution_1      = NAN,
                                    .solution_2      = NAN,
                                    .amount_solution = INITIALIZATION};

        solving_equation(&Generated_Equation);

        bool is_correct = Checking_all_solutions(&Generated_Equation);
        if (!is_correct){
            printf("ОШИБКА \n");
            printing_equation(Generated_Equation);
            printing_solutions(Generated_Equation);
        }
        correct_generated_tests += is_correct;
    }

    double gener_testst_accuracy = correct_generated_tests / amount_generated_tests;

    printf("\n Верных сгенерированных тестов %d из %d \n",
            correct_generated_tests, amount_generated_tests);

    return gener_testst_accuracy;
}


bool Checking_all_solutions(const Equation* Gener_Equation){
    assert(Gener_Equation);
    assert(isfinite(Gener_Equation->coefficients.coef_2));
    assert(isfinite(Gener_Equation->coefficients.coef_1));
    assert(isfinite(Gener_Equation->coefficients.coef_0));

    const Coefficients* Equation_Coefs = &(Gener_Equation->coefficients);

    bool is_correct_solution_1 = Checking_solution(Equation_Coefs, Gener_Equation->solution_1);
    bool is_correct_solution_2 = Checking_solution(Equation_Coefs, Gener_Equation->solution_2);

    if (isfinite(Gener_Equation->solution_1)) {
        if (isfinite(Gener_Equation->solution_2)) {
            return is_correct_solution_1 && is_correct_solution_2;

        } else if (!is_equal(finding_desc(Equation_Coefs), 0) && !is_equal(Equation_Coefs->coef_2, 0)) {
            return false;

        }
        return is_correct_solution_1;

    } else if ((is_equal(Equation_Coefs->coef_2, 0) && is_equal(Equation_Coefs->coef_1, 0)) ||
               finding_desc(Equation_Coefs) < 0){
        return true;
    }
    return false;
}




bool Checking_solution(const Coefficients* Equation_Coefs, const float solution){
    assert(Equation_Coefs);

    float substitution = Equation_Coefs->coef_2 * solution * solution +
                         Equation_Coefs->coef_1 * solution +
                         Equation_Coefs->coef_0;
    printf("root: %f, sust: %f, is zero: %d \n", solution, substitution, is_equal(substitution, 0));
    return is_equal(substitution, 0);
}

// void creating_equation_by_solutions(AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2){
// // asserts!!!!!
//     switch (amount_solutions){
//         case TWO_SOLUTIONS:
//             *coef_2 = 1;
//             *coef_1 = -(solution_1 + solution_2);
//             *coef_0 = solution_1 * solution_2;
//             break;
//
//         case(ONE_SOLUTION):
//             *coef_2 = 0;
//             *coef_1 = - solution_1;
//             break;
//         case PROBLEM:
//         case
//         default:
//             *coef_2 = 0;
//             *coef_1 = 0;
//             break;
//
//     }
// }
