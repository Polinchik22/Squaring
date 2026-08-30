#ifndef PAINTING_H
#define PAINTING_H

#include <raylib.h>
#include <stdio.h>
#include "general.h"
#include "input_output.h"


int const SCREEN_LENGTH = 800;
int const SCREEN_WIDTH  = 600;

int const DRAWING_STEP  = 10;

int     const mesh_size  = 20;
Vector2 const ZERO_POINT = {SCREEN_LENGTH/2 + SCREEN_LENGTH % mesh_size, SCREEN_WIDTH / 2 + SCREEN_WIDTH % mesh_size};


void Drawing               (const Coefficients Function_Coefs);

void Painting_function     (Coefficients Function_Coefs);

void Drawing_coordinates   ();

Vector2 Initializing_point (float pixel_axis_x, const Coefficients Function_Coefs);

float Function_value       (const float parameter, const Coefficients Function_Coefs);

float To_screen_coord      (float coord, char axis);
float To_func_coord        (float coord, char axis);

#endif //PAINTING_H
