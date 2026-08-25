#include "input_output.h"

bool entering_coefs(float* coef_2, float* coef_1, float* coef_0) {
    assert(coef_2);
    assert(coef_1);
    assert(coef_0);

    printf("Привет! будем решать ax^2 + bx + c = 0 \n");

    entering(coef_2, 'a');
    entering(coef_1, 'b');
    entering(coef_0, 'c');

    return true;
}


bool entering(float* coef, char litera){
    assert(coef);
    assert(litera);

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


bool printing_equation(Equation Square_Equation){
    assert(isfinite(Square_Equation.coef_2));
    assert(isfinite(Square_Equation.coef_1));
    assert(isfinite(Square_Equation.coef_0));

    printf("У уравнения: ");

    if (Square_Equation.amount_solution == INFINITY_SOLUTIONS){
        printf("0 = 0 \n");
        return true;
    }

    printing_coef(Square_Equation.coef_2, "x^2");
    printing_coef(Square_Equation.coef_1, "x"  );
    printing_coef(Square_Equation.coef_0, ""  );

    printf(" = 0 \n");

    return true;
}

bool printing_coef(const float coef, const char* x_part){
    if (coef >= 0) {
        if (x_part != "x^2") {
            printf("+ ");
        }
    } else {
        printf("- ");
    }

    float abs_coef = fabs(coef);
        if (is_equal(abs_coef, 0)){
            printf("0 ");

        } else if (is_equal(abs_coef, 1) && x_part != ""){
            printf("%s ", x_part);

        } else {
            printf("%g%s ", abs_coef, x_part);
        }

    return true;
}


bool printing_solutions(Equation Square_Equation) {
    printing_equation(Square_Equation);
    switch(Square_Equation.amount_solution){
            case (PROBLEM):
                printf("ПРОИЗОШЛА ОШИБКА/n");
                break;

            case (NO_SOLUTIONS):
                printf("Нет решений ┐(￣ヘ￣)┌ \n");
                break;

            case (ONE_SOLUTION):
                printf("1 решение: x1 = %g (＾▽＾) \n", Square_Equation.solution_1);
                break;

            case (TWO_SOLUTIONS):
                printf("2 решения: x1 = %g; x2 = %g (o˘◡˘o)\n", Square_Equation.solution_1, Square_Equation.solution_2);
                break;

            case (INFINITY_SOLUTIONS):
                printf("бесконечное количество решений (⊙_⊙)\n");
                break;

            default:
                printf("(^_-) ПРОИЗОШЛА ОШИБКА\n");
                break;
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

