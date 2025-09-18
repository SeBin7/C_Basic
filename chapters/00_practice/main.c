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

    PRINT_EXAMPLE("9-2");
    pointer_basic_example();

    PRINT_EXAMPLE("9-5");
    pointer_address_size_example();

    PRINT_EXAMPLE("9-7");
    pointer_example2();

    PRINT_EXAMPLE("10-3");
    pointer_array_example();

    PRINT_EXAMPLE("10-5");
    pointer_example2();
    return 0;
}