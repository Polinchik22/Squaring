#include <stdio.h>

#include "square_equation.h"
#include "testing_solving.h"
#include "input_output.h"
#include "tehnical_fiches.h"


int main() {
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

    printf("\n\n");

    Running_All_Tests();
}
