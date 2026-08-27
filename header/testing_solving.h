#ifndef TESTING_SOLVING_H
#define TESTING_SOLVING_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>


#include "square_equation.h"
#include "input_output.h"
#include "general.h"

double Starting_Test           ();

double Running_All_Hand_Tests  ();
bool   Running_Hand_Test       (const Equation Ref_Equation);

double Running_generated_tests (int amount_generated_tests);
bool   Checking_all_solutions  (const Equation* Generated_Equation);
bool   Checking_solution       (const Coefficients* Equation_Coefs, const float solution);

// void   creating_equation_by_solutions (AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2);

#endif //TESTING_SOLVING_H
