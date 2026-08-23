#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "general.h"


bool entering_coefs              (float* coef_2, float* coef_1, float* coef_0);
bool entering                    (float* coef, char litera);
bool is_correct_entering         (float* coef, char litera);

bool solving_equation (Equation* Square_Equation);
AmountSolutions solving_eq_deg2  (Equation* Square_Equation);
float finding_desc               (float coef_2, float coef_1, float coef_0);
AmountSolutions solving_eq_deg1  (Equation* Lineal_Equation);

bool printing_solutions          (Equation Square_Equation);

bool is_equal                    (float coef_2, float coef_1);
bool cleaning_buffer             ();

#endif //SQUARE_EQUATION_H
