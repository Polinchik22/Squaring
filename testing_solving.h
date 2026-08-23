#ifndef TESTING_SOLVING_H
#define TESTING_SOLVING_H


#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "square_equation.h"
#include "general.h"


double Running_All_Tests();
bool Running_Test(Equation Ref_Equation);
void printing_error(Equation Ref_Equation, Equation Prog_Equation);
void creating_equation_by_solutions(AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2);

#endif //TESTING_SOLVING_H
