#include "tehnical_fiches.h"


bool is_equal(float a, float b) {
    // Здесь осознано не пишу асерты, тк может принимать NAN

    int amount_nans = isnan(a) + isnan(b);

    if (amount_nans < 2) {
        return (fabs(a - b) < EPSILON);
    }
    return true;
}


bool cleaning_buffer() {
    char c = 0;
    while ((c = getchar()) != '\n') {
        if (c != ' '){
            while (getchar() != '\n');
            return false;
        }
    }
    return true;
}
