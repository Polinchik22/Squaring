#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "square_equation.cpp"
#include "testiing_solving.cpp"


int main() {
    Equation SqEquation = {.coef_2 = NAN, .coef_1 = NAN, .coef_0 = NAN,
                           .solution_1 = NAN, .solution_2 = NAN,
                           .amount_solution = INITIALIZATION};


    entering_coefs(&SqEquation.coef_2, &SqEquation.coef_1, &SqEquation.coef_0);

    SqEquation.amount_solution = solving_equation(SqEquation.coef_2, SqEquation.coef_1, SqEquation.coef_0, &SqEquation.solution_1, &SqEquation.solution_2);

    printing_solutions(SqEquation);

    printf("\n\n");

    printf("ПРОЦЕНТ КОРРЕКТНЫХ ТЕСТОВ %.f%% \n", Running_All_Tests());
}
