#include "testing_solving.h"

bool Starting_Test(){
    printf(BLUE "Хотите ли вы протестировать программу? [Y/N] " RESET);
    if (getchar() == 'Y'){
        printf("\n" BOLD_GREEN
               "Хорошо! Запускаю тестирование... ＼(≧▽≦)／ \n\n" RESET);

        Running_tests_from_fail();
        Running_All_Hand_Tests ();
        Running_generated_tests(AMOUNT_GENERATED_TESTS);

        return true;

    } else {
        printf("\n"
               "Не больно-то и хотелось (￣ヘ￣) \n"
               "Я всегда помогу! \n" RESET);

        return false;
    }

}


void Running_tests_from_fail(){
    bool is_run_tests_from_fail = chatting_about_file_testing();

    if (!is_run_tests_from_fail){
        return;
    }

    FILE* ftests = NULL;
    ftests = fopen("tests.tx", "r");

    if (ftests == NULL){
        printing_angry_emoje();
        printf(BOLD_RED "Ну ты и воздухан! Нет такого файла" RESET);
        return;
    }

    int correct_file_tests = 0;
    int amount__file_tests = 0;
    Equation Equation_from_file = {{.coef_2          = NAN,
                                    .coef_1          = NAN,
                                    .coef_0          = NAN},
                                    .solution_1      = NAN,
                                    .solution_2      = NAN,
                                    .amount_solution = INITIALIZATION};

    while (fscanf(ftests, "a = %f, b = %f, c = %f\n",
                &Equation_from_file.coefficients.coef_2,
                &Equation_from_file.coefficients.coef_1,
                &Equation_from_file.coefficients.coef_0) == READ_CORRECT_COEFFICIENTS){

        bool is_correct = Checking_all_solutions_by_coefs(&Equation_from_file);

        printing_error_in_tests(is_correct, Equation_from_file);

        correct_file_tests += is_correct;
        amount__file_tests++;
        }

    fclose(ftests);
    printf("\n" BOLD_GREEN "Верных проверок из фаила %d из %d" RESET, correct_file_tests, amount__file_tests);
}


void Running_All_Hand_Tests() {
    int correct_ref_tests = 0;

    for (int i = 0; i < AMOUNT_REF_TESTS; i++){
        correct_ref_tests += Running_Hand_Test(Ref_Book[i]);
    }
    printf("\n" BOLD_GREEN "Верных ручных проверок %d из %d" RESET, correct_ref_tests, AMOUNT_REF_TESTS);

}


bool Running_Hand_Test(const Equation Ref_Equation){
    //не нужны асерты

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


void Running_generated_tests(int amount_generated_tests){
    int correct_generated_tests = 0;

    for (int test_numb = 0; test_numb < amount_generated_tests; test_numb++){
        Equation Generated_Equation = {{frand(), frand(), frand()},
                                    .solution_1      = NAN,
                                    .solution_2      = NAN,
                                    .amount_solution = INITIALIZATION};

        bool is_correct = Checking_all_solutions_by_coefs(&Generated_Equation);

        printing_error_in_tests(is_correct, Generated_Equation);

        correct_generated_tests += is_correct;
    }

    printf(BOLD_GREEN "\n" "Верных сгенерированных тестов %d из %d \n" RESET,
            correct_generated_tests, amount_generated_tests);
}


bool Checking_all_solutions_by_coefs(Equation* Square_Equation){
    assert(Square_Equation);
    assert(isfinite(Square_Equation->coefficients.coef_2));
    assert(isfinite(Square_Equation->coefficients.coef_1));
    assert(isfinite(Square_Equation->coefficients.coef_0));

    const Coefficients* Equation_Coefs = &(Square_Equation->coefficients);

    solving_equation(Square_Equation);

    bool is_correct_solution_1 = Checking_solution(Equation_Coefs, Square_Equation->solution_1);
    bool is_correct_solution_2 = Checking_solution(Equation_Coefs, Square_Equation->solution_2);

    if (isfinite(Square_Equation->solution_1)) {
        if (isfinite(Square_Equation->solution_2)) {
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
