#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "general.h"
#include "tehnical_fiches.h"

void entering_all_coefs (Coefficients* Equation_Coefs);
void entering_one_coef  (float* coef, const char litera);

void printing_equation             (const Equation Square_Equation);
void printing_coef                 (const float coef, const char* x_part);
AmountSolutions printing_solutions (const Equation Square_Equation);

void printing_error_with_ref       (const Equation Ref_Equation, const Equation Prog_Equation);

#endif //INPUT_OUTPUT_H
