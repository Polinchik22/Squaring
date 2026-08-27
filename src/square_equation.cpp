#include "square_equation.h"


AmountSolutions solving_equation(Equation* Square_Equation) {
    assert(Square_Equation);

    if (is_equal(Square_Equation->coefficients.coef_2, 0)) {
        Square_Equation->amount_solution = solving_eq_deg1(Square_Equation);

    } else {
        Square_Equation->amount_solution = solving_eq_deg2(Square_Equation);
    }

    return Square_Equation->amount_solution;
}


AmountSolutions solving_eq_deg2(Equation* Square_Equation) {
    assert(Square_Equation);

    const Coefficients* Equation_Coefs = &(Square_Equation->coefficients);

    assert(isfinite(Equation_Coefs->coef_2));
    assert(isfinite(Equation_Coefs->coef_1));
    assert(isfinite(Equation_Coefs->coef_0));

    const float desc = finding_desc(Equation_Coefs);

    if (desc < 0) {
        return NO_SOLUTIONS;

    } else if (is_equal(desc, 0)) {
        Square_Equation->solution_1 = - Equation_Coefs->coef_1 / (2 * Equation_Coefs->coef_2);
        return ONE_SOLUTION;

    } else if (desc > 0) {
        float sqr_desc = sqrt(desc);

        Square_Equation->solution_1 = ( - Equation_Coefs->coef_1 + sqr_desc) / (2 * Equation_Coefs->coef_2);
        Square_Equation->solution_2 = ( - Equation_Coefs->coef_1 - sqr_desc) / (2 * Equation_Coefs->coef_2);
        return TWO_SOLUTIONS;

    } else {
        return PROBLEM;

    }
}


float finding_desc(const Coefficients* Equation_Coefs) {
    assert(Equation_Coefs);

    return (Equation_Coefs->coef_1 * Equation_Coefs->coef_1) - (4 * Equation_Coefs->coef_2 * Equation_Coefs->coef_0);
}


AmountSolutions solving_eq_deg1(Equation* Lineal_Equation) {
    assert(Lineal_Equation);

    const Coefficients* Equation_Coefs = &(Lineal_Equation->coefficients);

    assert(isfinite(Equation_Coefs->coef_2));
    assert(isfinite(Equation_Coefs->coef_1));
    assert(isfinite(Equation_Coefs->coef_0));

    if (is_equal(Equation_Coefs->coef_1, 0) && is_equal(Equation_Coefs->coef_0, 0)){
        return INFINITY_SOLUTIONS;

    } else if (is_equal(Equation_Coefs->coef_1, 0) && !is_equal(Equation_Coefs->coef_0, 0)){
        return NO_SOLUTIONS;

    }else{
        Lineal_Equation->solution_1 = ( - Equation_Coefs->coef_0 / Equation_Coefs->coef_1);
        return ONE_SOLUTION;
    }
}




