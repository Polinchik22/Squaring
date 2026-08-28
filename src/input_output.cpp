#include "input_output.h"

void entering_all_coefs(Coefficients* Equation_Coefs) {
    my_assert(Equation_Coefs);

    printf("Привет! будем решать ax^2 + bx + c = 0 \n");

    entering_one_coef(&(Equation_Coefs->coef_2), 'a');
    entering_one_coef(&(Equation_Coefs->coef_1), 'b');
    entering_one_coef(&(Equation_Coefs->coef_0), 'c');

    printf("\n");
}


void entering_one_coef(float* coef, const char litera){
    my_assert(coef);

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

    my_assert(isfinite(Equation_Coefs.coef_2));
    my_assert(isfinite(Equation_Coefs.coef_1));
    my_assert(isfinite(Equation_Coefs.coef_0));

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


void printing_error_in_tests(bool is_correct_test, Equation Solved_Equation){
    if (!is_correct_test){
            printf("ОШИБКА \n");
            printing_equation(Solved_Equation);
            printing_solutions(Solved_Equation);
        }
}


void printing_error_with_ref(const Equation Ref_Equation, const Equation Prog_Equation){
    printing_angry_emoje();
    printf(BOLD_RED "ОШИБКА \n" RESET);

    printing_equation(Ref_Equation);

    printf("Ожидалось  ");
    printing_solutions(Ref_Equation);

    printf("Получилось ");
    printing_solutions(Prog_Equation);
}


bool chatting_about_file_testing(){
    cleaning_buffer();

    printf(GREEN "Сори, Бро, последний вопрос (⁄ ⁄>⁄ ▽ ⁄<⁄ ⁄) \n\n"
               "Хочешь загрузить фаил с тестами? [Y/N] " RESET);

    if (getchar() == 'Y'){
        printf("\n" PINK
                "Просто ВАУ! Бро, ты лушчий пользователь, который юзает все фичи ( ´ ∀ `)ノ～ ♡  \n"
                "Проверяю тесты из фаила tests.txt, мои тесты с краевыми случаями и сгенерированные тесты \n\n" RESET);
        return true;
    }

    printf("\n" RED
           "Не хотите, как хотите. Баба с возу: кобыле легче..." RESET);
    return false;
}


void ai_use_chatting(){
    printf(BRIGHT_BOLD_BLUE "\n"
                            "Дорогой пользователь! В этой программе внедрен супер умный AI агент,"
                            "который будет делать все за тебя! \n"
                            "Представляешь, мозг вообще использовать не надо ☆*:.｡.o(≧▽≦)o.｡.:*☆ \n\n"
                            "Согласен его включить? [Y/N] " RESET);
    if (getchar() == 'Y'){
        printf(BOLD_RED "ВЫ ЗАБАНЕНЫ (ﾒ﹏ﾒ) \n" RESET);
        exit(1);
    }

    printf(BOLD_GREEN "Это была проверка и ты ее прощел! Я тебе помогу с математикой (o^ ^o) \n\n" RESET);
}

// void painting_function(const Equation Function){
//     char canvas[20][20];
// }


