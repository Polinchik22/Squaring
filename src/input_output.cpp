#include "input_output.h"

void Ai_use_chatting(){
    printf(BRIGHT_BOLD_BLUE "\n"
                            "Дорогой пользователь! В этой программе внедрен супер умный AI агент,"
                            "который будет делать все за тебя! \n"
                            "Представляешь, мозг вообще использовать не надо ☆*:.｡.o(≧▽≦)o.｡.:*☆ \n\n"
                            "Согласен его включить? [Y/N] " RESET);
    if (Is_yes()){
        printf(BOLD_RED "ВЫ ЗАБАНЕНЫ (ﾒ﹏ﾒ) \n" RESET);
        exit(1);
    }

    printf(BOLD_GREEN "Это была проверка и ты ее прощел! Я тебе помогу с математикой (o^ ^o) \n\n" RESET);
}


void Entering_all_coefs(Coefficients* Equation_Coefs) {
    my_assert(Equation_Coefs);

    printf("Будем решать ax^2 + bx + c = 0 \n");

    Entering_one_coef(&(Equation_Coefs->coef_2), 'a');
    Entering_one_coef(&(Equation_Coefs->coef_1), 'b');
    Entering_one_coef(&(Equation_Coefs->coef_0), 'c');

    printf("\n");
}


void Entering_one_coef(float* coef, const char litera){
    my_assert(coef);

    printf("Введи коэффициент %c: ", litera);

    bool was_scanned = false;
    while  (!(was_scanned = scanf("%f", coef)) || Cleaning_buffer() == false){
        if (!was_scanned){
            Cleaning_buffer();
        }
        printf(UNDERLINE_YELLOW "ЧУВААААК, давай без приколов," RESET " введи коэффициент %c: ", litera);
    }
}


void Printing_equation(const Equation Square_Equation){
    const Coefficients Equation_Coefs = Square_Equation.coefficients;

    my_assert(isfinite(Equation_Coefs.coef_2));
    my_assert(isfinite(Equation_Coefs.coef_1));
    my_assert(isfinite(Equation_Coefs.coef_0));

    printf("У уравнения: ");

    if (Square_Equation.amount_solution == INFINITY_SOLUTIONS){
        printf("0 = 0 \n");
        return;
    }

    Printing_coef(Equation_Coefs.coef_2, "x^2");
    Printing_coef(Equation_Coefs.coef_1, "x"  );
    Printing_coef(Equation_Coefs.coef_0, ""  );

    printf("= 0 \n");
    return;
}


void Printing_coef(const float coef, const char* x_part){
    my_assert(isfinite(coef));
    my_assert(x_part);

    if (coef >= 0) {
        if (strcmp(x_part, "x^2")) {
            printf("+ ");
        }
    } else {
        printf("- ");
    }

    float abs_coef = fabs(coef);

    if (Is_equal(abs_coef, 0)){
        printf("0 ");
    } else if (Is_equal(abs_coef, 1) && strcmp(x_part, "")){
        printf("%s ", x_part);
    } else {
        printf("%g%s ", abs_coef, x_part);
    }
}


AmountSolutions Printing_solutions(const Equation Square_Equation) {
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


void Printing_error_in_tests(bool is_correct_test, Equation Solved_Equation){
    if (!is_correct_test){
            printf("ОШИБКА \n");
            Printing_equation(Solved_Equation);
            Printing_solutions(Solved_Equation);
        }
}


void Printing_error_with_ref(const Equation Ref_Equation, const Equation Prog_Equation){
    Printing_angry_emoji();
    printf(BOLD_RED "ОШИБКА \n" RESET);

    Printing_equation(Ref_Equation);

    printf("Ожидалось  ");
    Printing_solutions(Ref_Equation);

    printf("Получилось ");
    Printing_solutions(Prog_Equation);
}


bool Chatting_about_file_testing(){
    printf(BLUE "Сори, Бро, последний вопрос (⁄ ⁄>⁄ ▽ ⁄<⁄ ⁄) \n\n"
               "Хочешь загрузить фаил с тестами? [Y/N] " RESET);

    if (Is_yes()){
        printf("\n" PINK
                "Просто ВАУ! Бро, ты лушчий пользователь, который юзает все фичи ( ´ ∀ `)ノ～ ♡  \n"
                "Проверяю тесты из фаила tests.txt, мои тесты с краевыми случаями и сгенерированные тесты \n\n" RESET);
        return true;
    }

    printf("\n" RED
           "Как говорится: баба с возу: кобыле легче..." RESET);
    return false;
}


// void painting_function(const Equation Function){
//     char canvas[20][20];
// }


