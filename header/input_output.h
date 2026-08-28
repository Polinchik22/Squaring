#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "general.h"
#include "tehnical_fiches.h"

void            Ai_use_chatting             ();

void            Entering_all_coefs          (Coefficients* Equation_Coefs);
void            Entering_one_coef           (float* coef, const char litera);

void            Printing_equation           (const Equation Square_Equation);
void            Printing_coef               (const float coef, const char* x_part);
AmountSolutions Printing_solutions          (const Equation Square_Equation);

void            Printing_error_in_tests     (bool is_correct_test, Equation Solved_Equation);
void            Printing_error_with_ref     (const Equation Ref_Equation, const Equation Prog_Equation);

bool            Chatting_about_file_testing ();

#endif //INPUT_OUTPUT_H
