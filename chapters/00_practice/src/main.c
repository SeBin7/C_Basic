#include "utils.h"
#include "practice_examples.h"

int main(void) {
    PRINT_EXAMPLE("3-3");
    integer_types();    

    PRINT_EXAMPLE("3-4");
    unsigned_overflow();

    PRINT_EXAMPLE("3-5");
    floating_precision();

    PRINT_EXAMPLE("4-2");
    division_remainder();

    PRINT_EXAMPLE("4-4");
    pre_post_example();

    PRINT_EXAMPLE("short_circuit");
    short_circuit();

    PRINT_EXAMPLE("4-9");
    sizeof_example();

    return 0;
}