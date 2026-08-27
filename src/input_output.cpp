#include "input_output.h"

void entering_all_coefs(Coefficients* Equation_Coefs) {
    assert(Equation_Coefs);

    printf("Привет! будем решать ax^2 + bx + c = 0 \n");

    entering_one_coef(&(Equation_Coefs->coef_2), 'a');
    entering_one_coef(&(Equation_Coefs->coef_1), 'b');
    entering_one_coef(&(Equation_Coefs->coef_0), 'c');

    printf("\n");
}


void entering_one_coef(float* coef, const char litera){
    assert(coef);

    printf("Введи коэффициент %c: ", litera);

    bool was_scanned = false;
    while  (!(was_scanned = scanf("%f", coef)) || cleaning_buffer() == false){
        if (!was_scanned){
            cleaning_buffer();
        }
        printf(UNDERLINE_YELLOW "ЧУВААААК, давай без приколов," RESET " введи коэффициент %c: ", litera);
    }
}


void printing_equation(const Equation Square_Equation){
    const Coefficients Equation_Coefs = Square_Equation.coefficients;

    assert(isfinite(Equation_Coefs.coef_2));
    assert(isfinite(Equation_Coefs.coef_1));
    assert(isfinite(Equation_Coefs.coef_0));

    printf("У уравнения: ");

    if (Square_Equation.amount_solution == INFINITY_SOLUTIONS){
        printf("0 = 0 \n");
        return;
    }

    printing_coef(Equation_Coefs.coef_2, "x^2");
    printing_coef(Equation_Coefs.coef_1, "x"  );
    printing_coef(Equation_Coefs.coef_0, ""  );

    printf("= 0 \n");
    return;
}


void printing_coef(const float coef, const char* x_part){
    assert(isfinite(coef));
    assert(x_part);

    if (coef >= 0) {
        if (strcmp(x_part, "x^2")) {
            printf("+ ");
        }
    } else {
        printf("- ");
    }

    float abs_coef = fabs(coef);

    if (is_equal(abs_coef, 0)){
        printf("0 ");
    } else if (is_equal(abs_coef, 1) && strcmp(x_part, "")){
        printf("%s ", x_part);
    } else {
        printf("%g%s ", abs_coef, x_part);
    }
}


AmountSolutions printing_solutions(const Equation Square_Equation) {
    switch(Square_Equation.amount_solution){
            case (PROBLEM):
                printf("ПРОИЗОШЛА ОШИБКА/n");
                break;

            case (NO_SOLUTIONS):
                printf("Нет решений ┐(￣ヘ￣)┌ \n\n");
                break;

            case (ONE_SOLUTION):
                printf("1 решение: x1 = %g (＾▽＾) \n\n", Square_Equation.solution_1);
                break;

            case (TWO_SOLUTIONS):
                printf("2 решения: x1 = %g; x2 = %g (o˘◡˘o) \n\n", Square_Equation.solution_1, Square_Equation.solution_2);
                break;

            case (INFINITY_SOLUTIONS):
                printf("Бесконечное количество решений (⊙_⊙) \n\n");
                break;

            case (INITIALIZATION):
            default:
                printf(BOLD_RED "ПРОИЗОШЛА ОШИБКА (^_-) \n\n" RESET);
                break;
        }
    return Square_Equation.amount_solution;
}


void printing_error_with_ref(const Equation Ref_Equation, const Equation Prog_Equation){
    printf(BOLD_RED "ОШИБКА \n" RESET);

    printing_equation(Ref_Equation);

    printf("Ожидалось  ");
    printing_solutions(Ref_Equation);

    printf("Получилось ");
    printing_solutions(Prog_Equation);
}


