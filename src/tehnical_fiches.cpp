#include "tehnical_fiches.h"


bool is_equal(const float a, const float b) {
    // Здесь осознано не пишу асcерты, тк может принимать NAN

    if (isnan(a) && isnan(b)){
        return true;
    }
    return (fabs(a - b) < EPSILON);
}


bool cleaning_buffer() {
    int c = 0;

    while ((c = getchar()) != '\n') {
        if (c != ' '){
            while (getchar() != '\n');
            return false;
        }
    }

    return true;
}


float frand(){
    return float(rand()) / float(rand() + 1);
}


void printing_angry_emoje(){

printf(RED "                @@@@@@@@@@@                \n"      );
printf(    "           -@@@@+         =@@@@=           \n"      );
printf(    "         @@@                   @@@         \n"      );
printf(    "       @@@                       @@@       \n"      );
printf(    "     @@@                           @@@     \n"      );
printf(    "    @@   @                      *@   @@    \n"      );
printf(    "   @@    @@                    -@     @@   \n"      );
printf(    "  @@#      @@@               @@@      #@@  \n"      );
printf(    "  @@         @@@@@@     @@@@@@         @@  \n"      );
printf(    "  @@        @@@@           @@@@        @@  \n"      );
printf(    " -@-        @@@@           @@@@        -@- \n"      );
printf(    " .@#        #@@@           @@@         *@. \n"      );
printf(    "  @@                                   @@  \n"      );
printf(    "  @@                                   @@  \n"      );
printf(    "   @@           @@@+@@@+@@@           @@   \n"      );
printf(    "    @@        @@           @@        @@    \n"      );
printf(    "     @@      #@             @#      @@     \n"      );
printf(    "      @@@    @               @    @@@      \n"      );
printf(    "        @@@                     @@@        \n"      );
printf(    "          @@@@               @@@@          \n"      );
printf(    "             +@@@@@@@@@@@@@@@+             \n" RESET);

}
