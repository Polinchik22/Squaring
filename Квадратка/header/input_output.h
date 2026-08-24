#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "general.h"
#include "tehnical_fiches.h"

bool entering_coefs      (float* coef_2, float* coef_1, float* const coef_0);
bool entering            (float* coef, char litera);


bool printing_equation   (Equation Square_Equation);
bool printing_coef       (const float coef, const char* x_part);
bool printing_solutions  (Equation Square_Equation);


void   printing_error     (Equation Ref_Equation, Equation Prog_Equation);

#endif //INPUT_OUTPUT_H
