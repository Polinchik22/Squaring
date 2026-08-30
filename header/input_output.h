///@file input_output.h
///@brief Responsible for program input and output
///interaction with the user, input of coefficients,
///output of the equation, output of roots, output of errors


#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "general.h"
#include "tehnical_fiches.h"

/// @brief Asks the user about the use of AI.
/// If the user wants to use AI, the program ends completely. Otherwise, the program continues.
void            Ai_use_chatting             ();

/// @brief Entering all coefficients
/// This continues until 3 numbers have been entered.
/// @param Equation_Coefs A pointer to the coefficient structure in which the entered coefficients will be stored.
void            Entering_all_coefs          (Coefficients* Equation_Coefs);

/// @brief Entering one coefficient and re‑prompting the user until a number is entered.
/// @param coef A pointer to the coefficient where the entered number will be stored
/// @param litera The letter “a”, “b”, or “c” is used to prompt the user to enter the specific coefficient they need.
void            Entering_one_coef           (float* coef, const char litera);

/// @brief Outputting the equation to the console
/// Cases where the coefficients are -1, 0, 1 are handled in a visually appealing way
/// Negative coefficients are output without + -
/// @param Square_Equation The equation displayed in read‑only mode.
/// The function uses the coefficients of the equation and the number of its solutions.
void            Printing_equation           (const Equation Square_Equation);

/// @brief
/// @param coef
/// @param x_part
void            Printing_coef               (const float coef, const char* x_part);
AmountSolutions Printing_solutions          (const Equation Square_Equation);

void            Printing_error_in_tests     (bool is_correct_test, Equation Solved_Equation);
void            Printing_error_with_ref     (const Equation Ref_Equation, const Equation Prog_Equation);

bool            Chatting_about_file_testing ();

#endif //INPUT_OUTPUT_H
