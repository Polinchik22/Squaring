#include "testing_solving.h"

bool Starting_test(){
    printf(COLOR_BLUE "Хотите ли вы протестировать программу? [Y/N] " COLOR_RESET);
    if (Is_yes()){
        printf(COLOR_BOLD_GREEN "Хорошо! Запускаю тестирование... ＼(≧▽≦)／ \n\n" COLOR_RESET);

        Running_tests_from_file();
        Running_all_hand_tests ();
        Running_generated_tests(AMOUNT_GENERATED_TESTS);

        return true;

    } else {
        printf(COLOR_BOLD_YELLOW "Не больно-то и хотелось (￣ヘ￣) \n\n" COLOR_RESET);

        return false;
    }

}


void Running_tests_from_file(){
    bool is_run_tests_from_fail = Chatting_about_file_testing();

    if (!is_run_tests_from_fail){
        return;
    }

    FILE* ftests = NULL;
    ftests = fopen("tests.txt", "r");

    if (ftests == NULL){
        Printing_angry_emoji();
        printf(COLOR_BOLD_RED "Ну ты и воздухан! Нет такого файла" COLOR_RESET);
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

        bool is_correct = Checking_solving_by_substitution(&Equation_from_file);

        Printing_error_in_tests(is_correct, Equation_from_file);

        correct_file_tests += is_correct;
        amount__file_tests++;
        }

    fclose(ftests);

    printf("\n" COLOR_BOLD_GREEN "Верных проверок из фаила %d из %d" COLOR_RESET, correct_file_tests, amount__file_tests);
}


void Running_all_hand_tests() {
    int correct_ref_tests = 0;

    for (int i = 0; i < AMOUNT_REF_TESTS; i++){
        correct_ref_tests += Running_hand_test(Ref_Book[i]);
    }
    printf("\n" COLOR_BOLD_GREEN "Верных ручных проверок %d из %d" COLOR_RESET, correct_ref_tests, AMOUNT_REF_TESTS);

}


bool Running_hand_test(const Equation Ref_Equation){
    Equation Prog_Equation = {Ref_Equation.coefficients,
                              .solution_1      = NAN,
                              .solution_2      = NAN,
                              .amount_solution = INITIALIZATION};

    Solving_equation(&Prog_Equation);

    if  (Ref_Equation.amount_solution != Prog_Equation.amount_solution    ||
            !Is_equal(Ref_Equation.solution_1, Prog_Equation.solution_1 ) ||
            !Is_equal(Ref_Equation.solution_2, Prog_Equation.solution_2)) {

        Printing_error_with_ref(Ref_Equation, Prog_Equation);

        return false;
        }

    return true;
}


void Running_generated_tests(int amount_generated_tests){
    int correct_generated_tests = 0;

    for (int test_numb = 0; test_numb < amount_generated_tests; test_numb++){
        Equation Generated_Equation = {{Frand(), Frand(), Frand()},
                                       .solution_1      = NAN,
                                       .solution_2      = NAN,
                                       .amount_solution = INITIALIZATION};

        bool is_correct = Checking_solving_by_substitution(&Generated_Equation);

        Printing_error_in_tests(is_correct, Generated_Equation);

        correct_generated_tests += is_correct;
    }

    printf(COLOR_BOLD_GREEN "\n" "Верных сгенерированных тестов %d из %d \n\n" COLOR_RESET,
            correct_generated_tests, amount_generated_tests);
}


bool Checking_solving_by_substitution(Equation* Square_Equation){
    my_assert(Square_Equation);
    my_assert(isfinite(Square_Equation->coefficients.coef_2));
    my_assert(isfinite(Square_Equation->coefficients.coef_1));
    my_assert(isfinite(Square_Equation->coefficients.coef_0));

    const Coefficients* Equation_Coefs = &(Square_Equation->coefficients);

    Solving_equation(Square_Equation);

    bool is_correct_solution_1 = Checking_substitution(Equation_Coefs, Square_Equation->solution_1);
    bool is_correct_solution_2 = Checking_substitution(Equation_Coefs, Square_Equation->solution_2);

    if (isfinite(Square_Equation->solution_1)) {
        if (isfinite(Square_Equation->solution_2)) {
            return is_correct_solution_1 && is_correct_solution_2;

        } else if (!Is_equal(Finding_desc(Equation_Coefs), 0) && !Is_equal(Equation_Coefs->coef_2, 0)) {
            return false;

        }
        return is_correct_solution_1;

    } else if ((Is_equal(Equation_Coefs->coef_2, 0) && Is_equal(Equation_Coefs->coef_1, 0)) ||
               Finding_desc(Equation_Coefs) < 0){
        return true;
    }
    return false;
}


bool Checking_substitution(const Coefficients* Equation_Coefs, const float solution){
    my_assert(Equation_Coefs);

    float substitution = Equation_Coefs->coef_2 * solution * solution +
                         Equation_Coefs->coef_1 * solution +
                         Equation_Coefs->coef_0;
    return Is_equal(substitution, 0);
}

// void creating_equation_by_solutions(AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2){
// // my_asserts!!!!!
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
