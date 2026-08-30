/// @file general.h
/// @brief Description of the structures used in all project files.


#ifndef GENERAL_H
#define GENERAL_H

/// @brief The number of solutions a quadratic equation can have.
enum AmountSolutions {INITIALIZATION = -2,
                      PROBLEM,
                      NO_SOLUTIONS,
                      ONE_SOLUTION,
                      TWO_SOLUTIONS,
                      INFINITY_SOLUTIONS};

/// @brief The epsilon value, for the epsilon neighborhood, through which the numbers will be compared.
const float EPSILON      = 1e-4f;

/// @brief 3 coefficients of the equation
/// Index is consistent with the degree of the variable.
struct Coefficients {
    float coef_2, coef_1, coef_0;
};

/// @brief Structure for equation
/// It includes: a structure consisting of three coefficients of the equation;
/// 2 roots of the equation (if there is no specific root, the variable value is NAN).
///If the root is 1, it is always recorded in solution_1. The roots are recorded in descending order;
///The number of solutions to the equation in the format of enum AmountSolutions.
struct Equation {
    Coefficients coefficients;
    float solution_1, solution_2;
    AmountSolutions amount_solution;
};

/// @brief Colors transmitted via “\033” encoded via ANSI.
#define COLOR_BOLD_RED         "\033[1;31m"
#define COLOR_RED              "\033[31m"
#define COLOR_UNDERLINE_YELLOW "\033[4;93m"
#define COLOR_BOLD_YELLOW      "\033[1;93m"
#define COLOR_BOLD_GREEN       "\033[1;32m"
#define COLOR_GREEN            "\033[32m"
#define COLOR_BLUE             "\033[36m"
#define COLOR_BRIGHT_BOLD_BLUE "\033[1;94m"
#define COLOR_PINK             "\033[1;38;5;201m"
#define COLOR_BOLD_PURPLE      "\033[1;95m"
#define COLOR_RESET            "\033[0m"

/// @brief An error output micros that displays the file, function, and line number where the error occurred.
/// Disabled by the NDEBUG ad
#ifndef NDEBUG
#define my_assert(statement)                                                                               \
            if (!statement){                                                                               \
                Printing_angry_emoji();                                                                    \
                printf(COLOR_BOLD_RED "Вы жестко ******.! \n"                                 COLOR_RESET  \
                       COLOR_RED      "Конкретнее: в фаиле %s, в функции %s на строчке %d \n" COLOR_RESET, \
                        __FILE__, __func__, __LINE__);                                                     \
            abort();                                                                                       \
            }
#else
#define my_assert(statement) ((void)0)

#endif //NOTDEBUG

#endif //GENERAL_H
