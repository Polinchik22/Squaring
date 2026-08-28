#include <stdio.h>
#include <stdlib.h>

#include "square_equation.h"
#include "testing_solving.h"
#include "input_output.h"
#include "tehnical_fiches.h"

#define NDEBUG

#include <assert.h>


int main() {
    // my_assert(0);
    Ai_use_chatting();

    Starting_test();

    Equation Square_Equation = {{.coef_2          = NAN,
                                 .coef_1          = NAN,
                                 .coef_0          = NAN},
                                 .solution_1      = NAN,
                                 .solution_2      = NAN,
                                 .amount_solution = INITIALIZATION};

    Entering_all_coefs(&(Square_Equation.coefficients));

    Solving_equation(&Square_Equation);

    Printing_equation(Square_Equation);
    Printing_solutions(Square_Equation);

    printf("\n");
}
