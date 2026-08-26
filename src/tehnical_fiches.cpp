#include "tehnical_fiches.h"


bool is_equal(const float a, const float b) {
    // Здесь осознано не пишу асcерты, тк может принимать NAN

    int amount_nans = isnan(a) + isnan(b);

    if (amount_nans < 2) { // todo
        return (fabs(a - b) < EPSILON);
    }
    return true;
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
