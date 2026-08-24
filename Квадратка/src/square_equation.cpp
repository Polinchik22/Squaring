#include "square_equation.h"


bool solving_equation(Equation* Square_Equation) {
    assert(isfinite(Square_Equation->coef_2));
    assert(isfinite(Square_Equation->coef_1));
    assert(isfinite(Square_Equation->coef_0));
    assert(&(Square_Equation->solution_1));
    assert(&(Square_Equation->solution_2));

    if (is_equal(Square_Equation->coef_2, 0)) {
        Square_Equation->amount_solution = solving_eq_deg1(Square_Equation);

    } else {
        Square_Equation->amount_solution = solving_eq_deg2(Square_Equation);
    }

    return true;
}


AmountSolutions solving_eq_deg2(Equation* Square_Equation) {
    assert(isfinite(Square_Equation->coef_2));
    assert(isfinite(Square_Equation->coef_1));
    assert(isfinite(Square_Equation->coef_0));
    assert(&(Square_Equation->solution_1));
    assert(&(Square_Equation->solution_2));

    float desc = finding_desc(Square_Equation->coef_2, Square_Equation->coef_1, Square_Equation->coef_0);

    if (desc < 0) {
        return NO_SOLUTIONS;

    } else if (is_equal(desc, 0)) {
        Square_Equation->solution_1 = -Square_Equation->coef_1 / (2 * Square_Equation->coef_2);
        return ONE_SOLUTION;

    } else if (desc > 0) {
        float sqr_desc = sqrt(desc);

        Square_Equation->solution_1 = ( - Square_Equation->coef_1 + sqr_desc) / (2 * Square_Equation->coef_2);
        Square_Equation->solution_2 = ( - Square_Equation->coef_1 - sqr_desc) / (2 * Square_Equation->coef_2);
        return TWO_SOLUTIONS;

    } else {
        return PROBLEM;

    }
}


float finding_desc(const float coef_2, float coef_1, float coef_0) {
    assert(isfinite(coef_2));
    assert(isfinite(coef_1));
    assert(isfinite(coef_0));

    return (coef_1 * coef_1) - (4 * coef_2 * coef_0);

}


AmountSolutions solving_eq_deg1(Equation* Lineal_Equation) {
    assert(isfinite(Lineal_Equation->coef_2));
    assert(isfinite(Lineal_Equation->coef_1));
    assert(isfinite(Lineal_Equation->coef_0));
    assert(&(Lineal_Equation->solution_1));
    assert(&(Lineal_Equation->solution_2));

    if (is_equal(Lineal_Equation->coef_1, 0) && is_equal(Lineal_Equation->coef_0, 0)){
        return INFINITY_SOLUTIONS;

    } else if (is_equal(Lineal_Equation->coef_1, 0) && !is_equal(Lineal_Equation->coef_0, 0)){
        return NO_SOLUTIONS;

    }else{
        Lineal_Equation->solution_1 = (-Lineal_Equation->coef_0 / Lineal_Equation->coef_1);
        return ONE_SOLUTION;

    }
}




