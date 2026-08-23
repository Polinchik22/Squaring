#include "input_output.h"

bool entering_coefs(float* coef_2, float* coef_1, float* coef_0) {
    printf("Привет! будем решать ax^2 + bx + c = 0 \n");

    entering(coef_2, 'a');
    entering(coef_1, 'b');
    entering(coef_0, 'c');

    return true;
}
//TODO: асерты, разделить на фаилы, защита const, проработать вывод уравнения


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


bool printing_solutions(Equation Square_Equation) {
    // char coef_form[3] = {'', 'x^2', '%.2lfx^2'}
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
