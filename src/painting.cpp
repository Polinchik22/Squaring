#include "painting.h"

void Drawing(const Coefficients Function_Coefs){
    SetTraceLogLevel(LOG_NONE);

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(SCREEN_LENGTH, SCREEN_WIDTH, "Painting");

	while (!WindowShouldClose()){
		BeginDrawing();

        ClearBackground(BLACK);

        Painting_function(Function_Coefs);

		DrawText("FUCK! Close window", 100, 50, 20, WHITE);

		EndDrawing();
	}

	CloseWindow();
}


void Painting_function(Coefficients Function_Coefs){
    Drawing_coordinates();

    Vector2 Current_Point = {0, 0};
    Vector2 Previous_Point = Initializing_point(0, Function_Coefs);


    for (float pixel_axis_x = 0; pixel_axis_x < SCREEN_LENGTH; pixel_axis_x += DRAWING_STEP){
        Current_Point = Initializing_point(pixel_axis_x, Function_Coefs);

        DrawLineV(Previous_Point, Current_Point, SKYBLUE);

        Previous_Point = Current_Point;
    }

}


void Drawing_coordinates(){
    for (int horizontal_line_place = 0;
            horizontal_line_place < SCREEN_WIDTH;
            horizontal_line_place += mesh_size){

        DrawLine(0, horizontal_line_place, SCREEN_LENGTH, horizontal_line_place, DARKGRAY);
    }

    for (int vertical_line_place =  0            ;
             vertical_line_place <  SCREEN_LENGTH;
             vertical_line_place += mesh_size    ){

        DrawLine(vertical_line_place, 0, vertical_line_place, SCREEN_WIDTH, DARKGRAY);
    }

    DrawLine(0                , (int)ZERO_POINT.y,      SCREEN_LENGTH, (int)ZERO_POINT.y, GOLD);
    DrawLine((int)ZERO_POINT.x, 0                , (int)ZERO_POINT.x ,      SCREEN_WIDTH, GOLD);

    DrawText("0", (int)ZERO_POINT.x + 5, (int)ZERO_POINT.y + 5, 10, WHITE);
}


Vector2 Initializing_point(float pixel_axis_x, Coefficients Function_Coefs){
    float function_axis_x = To_func_coord(pixel_axis_x, 'x');

    float function_axis_y = Function_value(function_axis_x, Function_Coefs);

    float pixel_axis_y    = To_screen_coord(function_axis_y, 'y');

    return {pixel_axis_x, pixel_axis_y};
}



float Function_value(const float parameter,
                     const Coefficients Function_Coefs){

    return Function_Coefs.coef_2 * parameter * parameter + \
           Function_Coefs.coef_1 * parameter +             \
           Function_Coefs.coef_0;

}


float To_screen_coord(float coord, char axis){
    switch (axis){
        case 'x':
            return coord * mesh_size + ZERO_POINT.x;

        case 'y':
            return ZERO_POINT.y - coord * mesh_size;

        default:
            printf("Ошибка в функции To_screen_coord");
            return 0;
    }
}


float To_func_coord(float coord, char axis){
    switch (axis){
        case 'x':
            return (coord - ZERO_POINT.x) / (float)mesh_size;

        case 'y':
            return (ZERO_POINT.y - coord) / (float)mesh_size;

        default:
            printf("Ошибка в функции To_screen_coord");
            return 0;
    }
}

