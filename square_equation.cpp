#include "square_equation.h"


bool entering_coefs(float* coef_2, float* coef_1, float* coef_0) {
    printf("Привет! будем решать ax^2 + bx + c = 0 \n");

    entering(coef_2, 'a');
    entering(coef_1, 'b');
    entering(coef_0, 'c');

    return true;
}


bool entering(float* coef, char litera){
    printf("введи коэффициент %c: ", litera);
    bool amount = 0;
    while ((amount = scanf("%f", coef)) != 1 || cleaning_buffer() == false){
        if (amount == 0){
            cleaning_buffer();
        }
        printf("ЧУВААААК, давай без приколов, введи коэффициент %c: ", litera);
    }

    return true;
}


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


float finding_desc(float coef_2, float coef_1, float coef_0) {
    assert(isfinite(coef_2));
    assert(isfinite(coef_1));
    assert(isfinite(coef_0));

    return (coef_1 * coef_1) - (4 * coef_2 * coef_0);

}


AmountSolutions solving_eq_deg1(Equation* Lineal_Equation) {
    assert(isfinite(Lineal_Equation->coef_1));
    assert(isfinite(Lineal_Equation->coef_0));
    assert(&(Lineal_Equation->solution_1)); //TODO - спросить есть ли более оптимальная запись

    if (is_equal(Lineal_Equation->coef_1, 0) && is_equal(Lineal_Equation->coef_0, 0)){
        return INFINITY_SOLUTIONS;

    } else if (is_equal(Lineal_Equation->coef_1, 0) && !is_equal(Lineal_Equation->coef_0, 0)){
        return NO_SOLUTIONS;

    }else{
        Lineal_Equation->solution_1 = (-Lineal_Equation->coef_0 / Lineal_Equation->coef_1);
        return ONE_SOLUTION;

    }
}


bool printing_solutions(Equation Square_Equation) {
    switch(Square_Equation.amount_solution){
            case (PROBLEM):
                printf("ПРОИЗОШЛА ОШИБКА/n");
                break;

            case (NO_SOLUTIONS):
                printf("┐(￣ヘ￣)┌ У уравнения %.2lfx^2 + %.2lfx + %.2lf = 0 нет решений\n", Square_Equation.coef_2, Square_Equation.coef_1, Square_Equation.coef_0);
                break;

            case (ONE_SOLUTION):
                printf("(＾▽＾) У уравнения %.2lfx^2 + %.2lfx + %.2lf = 0 \n"
                       "1 корень: %.2lf\n", Square_Equation.coef_2, Square_Equation.coef_1, Square_Equation.coef_0, Square_Equation.solution_1);
                break;

            case (TWO_SOLUTIONS):
                printf("(o˘◡˘o) У уравнения %.2lfx^2 + %.2lfx + %.2lf = 0 \n"
                       "2 корня: %.2lf и %.2lf\n", Square_Equation.coef_2, Square_Equation.coef_1, Square_Equation.coef_0, Square_Equation.solution_1, Square_Equation.solution_2);
                break;

            case (INFINITY_SOLUTIONS):
                printf("(⊙_⊙) У уравнения %.2lfx^2 + %.2lfx + %.2lf = 0 \n"
                       "бесконечное количество решений\n", Square_Equation.coef_2, Square_Equation.coef_1, Square_Equation.coef_0);
                break;

            default:
                printf("(^_-) ПРОИЗОШЛА ОШИБКА\n");
                break;
        }
    return true;
}


bool is_equal(float a, float b) {
    int amount_nans = isnan(a) + isnan(b);

    if (amount_nans < 2) {
        return (fabs(a - b) < EPSILON);
    }
    return true;
}


bool cleaning_buffer() {
    char c = 0;
    while ((c = getchar()) != '\n') {
        if (c != ' '){
            while (getchar() != '\n') {;}
            return false;
        }
    }
    return true;
}


