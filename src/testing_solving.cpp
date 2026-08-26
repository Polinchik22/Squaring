#include "testing_solving.h"


double Running_All_Tests() {
    int correct_tests = 0;
    const Equation Ref_Book[AMOUNT_TESTS] = {
        {{.coef_2 = 1, .coef_1 = -5, .coef_0 =   6}, .solution_1 =  3  , .solution_2 = 2  , .amount_solution = TWO_SOLUTIONS     },
        {{.coef_2 = 1, .coef_1 =  2, .coef_0 =   1}, .solution_1 = -1  , .solution_2 = NAN, .amount_solution = ONE_SOLUTION      },
        {{.coef_2 = 0, .coef_1 =  1, .coef_0 =  -1}, .solution_1 =  2  , .solution_2 = NAN, .amount_solution = ONE_SOLUTION      },
        {{.coef_2 = 1, .coef_1 =  0, .coef_0 =   1}, .solution_1 =  NAN, .solution_2 = NAN, .amount_solution = NO_SOLUTIONS      },
        {{.coef_2 = 1, .coef_1 =  1, .coef_0 =  23}, .solution_1 =  NAN, .solution_2 = NAN, .amount_solution = NO_SOLUTIONS      },
        {{.coef_2 = 0, .coef_1 =  0, .coef_0 =   0}, .solution_1 =  NAN, .solution_2 = NAN, .amount_solution = INFINITY_SOLUTIONS},
    };

    for (int i = 0; i < AMOUNT_TESTS; i++){
        Equation Ref_Equation = Ref_Book[i];

        correct_tests += Running_Test(Ref_Equation);
    }

    double accuracy = correct_tests / AMOUNT_TESTS;

    printf("\n Верных тестов %d из %d \n", correct_tests, AMOUNT_TESTS);
    return accuracy;
}


bool Running_Test(Equation Ref_Equation){
    Equation Prog_Equation = {Ref_Equation.coefficients,
                              .solution_1      = NAN,
                              .solution_2      = NAN,
                              .amount_solution = INITIALIZATION};

    solving_equation(&Prog_Equation);

if     (Ref_Equation.amount_solution != Prog_Equation.amount_solution ||
        !is_equal(Ref_Equation.solution_1, Prog_Equation.solution_1 ) ||
        !is_equal(Ref_Equation.solution_2, Prog_Equation.solution_2)) {

    printing_error(Ref_Equation, Prog_Equation);
    return false;
    }

    return true;
}


// bool cheking_all_solutions(const Equation* Prog_Equation){
//     assert(isfinite(Prog_Equation->coef_2));
//     assert(isfinite(Prog_Equation->coef_1));
//     assert(isfinite(Prog_Equation->coef_0));
//     assert(&(Prog_Equation->solution_1));
//     assert(&(Prog_Equation->solution_2));
//
//     if
//
// }
//
//
// bool cheking_one_solution(const Coefficients* Equation_Coefs, const float solution){
//     double substitution = 0;
// }


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
