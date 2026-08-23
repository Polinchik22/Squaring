#include <stdio.h>

#include "square_equation.h"
#include "testing_solving.h"


int main() {
    Equation Square_Equation = {.coef_2 = NAN, .coef_1 = NAN, .coef_0 = NAN,
                           .solution_1 = NAN, .solution_2 = NAN,
                           .amount_solution = INITIALIZATION};


    entering_coefs(&Square_Equation.coef_2, &Square_Equation.coef_1, &Square_Equation.coef_0);

    solving_equation(&Square_Equation);

    printing_solutions(Square_Equation);

    printf("\n\n");

    printf("ПРОЦЕНТ КОРРЕКТНЫХ ТЕСТОВ %.f%% \n", Running_All_Tests());
}
