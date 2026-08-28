#ifndef TESTING_SOLVING_H
#define TESTING_SOLVING_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>


#include "square_equation.h"
#include "input_output.h"
#include "general.h"

int const READ_CORRECT_COEFFICIENTS = 3;

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

bool Starting_Test           ();

void Running_tests_from_fail ();
void Running_All_Hand_Tests  ();
bool Running_Hand_Test       (const Equation Ref_Equation);

void Running_generated_tests         (int amount_generated_tests);
bool Checking_all_solutions_by_coefs (Equation* Generated_Equation);
bool Checking_solution               (const Coefficients* Equation_Coefs, const float solution);

// void   creating_equation_by_solutions (AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2);

#endif //TESTING_SOLVING_H
