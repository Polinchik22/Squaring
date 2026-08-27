#include <stdio.h>
#include <stdlib.h>

#include "square_equation.h"
#include "testing_solving.h"
#include "input_output.h"
#include "tehnical_fiches.h"

#define NDEBUG


int main() {
    my_assert(0);

    Equation Square_Equation = {{.coef_2          = NAN,
                                 .coef_1          = NAN,
                                 .coef_0          = NAN},
                                 .solution_1      = NAN,
                                 .solution_2      = NAN,
                                 .amount_solution = INITIALIZATION};

    entering_all_coefs(&(Square_Equation.coefficients));

    solving_equation(&Square_Equation);

    printing_equation(Square_Equation);
    printing_solutions(Square_Equation);

    Starting_Test();

    printf("\n");
}
