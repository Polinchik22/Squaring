#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "general.h"
#include "tehnical_fiches.h"

AmountSolutions Solving_equation (Equation* Square_Equation);

AmountSolutions Solving_eq_deg2  (Equation* Square_Equation);
float           Finding_desc     (const Coefficients* Equation_Coefs);

AmountSolutions Solving_eq_deg1  (Equation* Lineal_Equation);

#endif //SQUARE_EQUATION_H
