#ifndef GENERAL_H
#define GENERAL_H

enum AmountSolutions {INITIALIZATION = -2,
                      PROBLEM,
                      NO_SOLUTIONS,
                      ONE_SOLUTION,
                      TWO_SOLUTIONS,
                      INFINITY_SOLUTIONS};

const float EPSILON      = 1e-4f;
const int   AMOUNT_REF_TESTS = 9;
const int   AMOUNT_GENERATED_TESTS = 100;


struct Coefficients {
    float coef_2, coef_1, coef_0;
};


struct Equation {
    Coefficients coefficients;
    float solution_1, solution_2;
    AmountSolutions amount_solution;
};

#define BOLD_RED          "\033[1;31m"
#define UNDERLINE_YELLOW  "\033[4;93m"
#define BOLD_GREEN        "\033[1;32m"
#define RESET             "\033[0m"
#define BLUE              "\033[36m"

#endif //GENERAL_H
