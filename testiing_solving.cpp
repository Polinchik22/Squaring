#include <stdio.h>
#include <assert.h>
#include <math.h>


enum AmountSolutions {INITIALIZATION = -2,
                      PROBLEM,
                      NO_SOLUTIONS,
                      ONE_SOLUTION,
                      TWO_SOLUTIONS,
                      INFINITY_SOLUTIONS};

const float EPSILON = 1e-6f;


struct Equation{
    float coef_2, coef_1, coef_0;
    float solution_1, solution_2;
    AmountSolutions amount_solution;
};


int Running_All_Tests();
bool Running_Test(Equation Ref_Equation);
void printing_error(Equation Ref_Equation, Equation Prog_Equation);
void creating_equation_by_solutions(AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2);


int Running_All_Tests() {
    Equation Ref_Equation = {.coef_2 = 1, .coef_1 = -5, .coef_0 = 6,
                             .solution_1 = 3, .solution_2 = 2,
                             .amount_solution = TWO_SOLUTIONS};


    bool is_correct = Running_Test(Ref_Equation);

    return (int)is_correct;
}

bool Running_Test(Equation Ref_Equation){
    Equation Prog_Equation = {.coef_2 = Ref_Equation.coef_2, .coef_1 = Ref_Equation.coef_1, .coef_0 = Ref_Equation.coef_0,
                              .solution_1 = NAN, .solution_2 = NAN,
                              .amount_solution = INITIALIZATION};


    Prog_Equation.amount_solution = solving_equation(Ref_Equation.coef_2, Ref_Equation.coef_1, Ref_Equation.coef_0, &Prog_Equation.solution_1, &Prog_Equation.solution_2);

    if (Prog_Equation.amount_solution != Ref_Equation.amount_solution || (is_equal(Ref_Equation.solution_1, Prog_Equation.solution_1) + is_equal(Ref_Equation.solution_2, Prog_Equation.solution_2) != Ref_Equation.amount_solution)) {
        printing_error(Ref_Equation, Prog_Equation);
        return false;
    }
    return true;
}


void printing_error(Equation Ref_Equation, Equation Prog_Equation){
    printf("ОШИБКА в решении уравнения: %.2lfx^2 + %.2lfx + %.2lf = 0 \n"
           "Ожидалось  %d решений: первое %5.2lf, второе %5.2lf\n"
           "Получилось %d решений: первое %5.2lf, второе %5.2lf\n",
           Ref_Equation.coef_2, Ref_Equation.coef_1, Ref_Equation.coef_0,
           Ref_Equation.amount_solution, Ref_Equation.solution_1, Ref_Equation.solution_2,
           Prog_Equation.amount_solution, Prog_Equation.solution_1, Prog_Equation.solution_2);
}


void creating_equation_by_solutions(AmountSolutions amount_solutions, float* coef_2, float* coef_1, float* coef_0, float solution_1, float solution_2){
    switch (amount_solutions){
        case(TWO_SOLUTIONS):
            *coef_2 = 1;
            *coef_1 = -(solution_1 + solution_2);
            *coef_0 = solution_1 * solution_2;

        case(ONE_SOLUTION):
            *coef_2 = 0;
            *coef_1 = - solution_1;
    }
}
