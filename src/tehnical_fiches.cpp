#include "tehnical_fiches.h"


bool Is_equal(const float a, const float b) {
    // Здесь осознано не пишу асcерты, тк может принимать NAN
    if (isnan(a) && isnan(b)){
        return true;
    }
    return (fabs(a - b) < EPSILON);
}


bool Cleaning_buffer() {
    int c = 0;

    while ((c = getchar()) != '\n') {
        if (c != ' '){
            while (getchar() != '\n');
            return false;
        }
    }

    return true;
}


float Frand(){
    return float(rand()) / float(rand() + 1);
}


bool Is_yes(){
    int c = getchar();
    Cleaning_buffer();

    if (c == 'Y' || c == 'y'){
        return true;
    }
    return false;
}


void Printing_angry_emoji(){

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
