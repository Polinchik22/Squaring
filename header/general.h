#ifndef GENERAL_H
#define GENERAL_H

enum AmountSolutions {INITIALIZATION = -2,
                      PROBLEM,
                      NO_SOLUTIONS,
                      ONE_SOLUTION,
                      TWO_SOLUTIONS,
                      INFINITY_SOLUTIONS};

const float EPSILON      = 1e-6f;
const int   AMOUNT_TESTS = 6;


struct Coefficients {
    float coef_2, coef_1, coef_0;
};


struct Equation {
    Coefficients coefficients;
    float solution_1, solution_2;
    AmountSolutions amount_solution;
};

#endif //GENERAL_H
