#include "square_equation.h"


AmountSolutions Solving_equation(Equation* Square_Equation) {
    my_assert(Square_Equation);

    if (Is_equal(Square_Equation->coefficients.coef_2, 0)) {
        Square_Equation->amount_solution = Solving_eq_deg1(Square_Equation);

    } else {
        Square_Equation->amount_solution = Solving_eq_deg2(Square_Equation);
    }

    return Square_Equation->amount_solution;
}


AmountSolutions Solving_eq_deg2(Equation* Square_Equation) {
    my_assert(Square_Equation);

    const Coefficients* Equation_Coefs = &(Square_Equation->coefficients);

    my_assert(isfinite(Equation_Coefs->coef_2));
    my_assert(isfinite(Equation_Coefs->coef_1));
    my_assert(isfinite(Equation_Coefs->coef_0));

    const float desc = Finding_desc(Equation_Coefs);

    if (desc < 0) {
        Square_Equation->solution_1 = NAN;
        Square_Equation->solution_2 = NAN;

        return NO_SOLUTIONS;

    } else if (Is_equal(desc, 0)) {
        Square_Equation->solution_1 = - Equation_Coefs->coef_1 / (2 * Equation_Coefs->coef_2);
        Square_Equation->solution_2 = NAN;

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


float Finding_desc(const Coefficients* Equation_Coefs) {
    my_assert(Equation_Coefs);

    return (Equation_Coefs->coef_1 * Equation_Coefs->coef_1) - (4 * Equation_Coefs->coef_2 * Equation_Coefs->coef_0);
}


AmountSolutions Solving_eq_deg1(Equation* Lineral_Equation) {
    my_assert(Lineral_Equation);

    const Coefficients* Equation_Coefs = &(Lineral_Equation->coefficients);

    my_assert(isfinite(Equation_Coefs->coef_2));
    my_assert(isfinite(Equation_Coefs->coef_1));
    my_assert(isfinite(Equation_Coefs->coef_0));

    if (Is_equal(Equation_Coefs->coef_1, 0) && Is_equal(Equation_Coefs->coef_0, 0)){
        Lineral_Equation->solution_1 = NAN;
        Lineral_Equation->solution_2 = NAN;

        return INFINITY_SOLUTIONS;

    } else if (Is_equal(Equation_Coefs->coef_1, 0) && !Is_equal(Equation_Coefs->coef_0, 0)){
        Lineral_Equation->solution_1 = NAN;
        Lineral_Equation->solution_2 = NAN;

        return NO_SOLUTIONS;

    }else{
        Lineral_Equation->solution_1 = ( - Equation_Coefs->coef_0 / Equation_Coefs->coef_1);
        Lineral_Equation->solution_2 = NAN;

        return ONE_SOLUTION;
    }
}




