#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "general.h"
#include "tehnical_fiches.h"

AmountSolutions solving_equation (Equation* Square_Equation);
AmountSolutions solving_eq_deg2  (Equation* Square_Equation);
float finding_desc               (const Coefficients* Equation_Coefs);
AmountSolutions solving_eq_deg1  (Equation* Lineal_Equation);

#endif //SQUARE_EQUATION_H
