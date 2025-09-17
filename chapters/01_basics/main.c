#include <stdio.h>
#include "variables.h"
#include "pointers_memory.h"
#include "operators.h"
#include "functions.h"
#include "arrays.h"
#include "strings.h"
#include "structs_enums.h"

int main(void) {
    puts("=== 01_basics: variables vs pointers/memory ===\n");

    /* Variables-only section */
    literals_and_types();
    initialization_and_scope();
    format_specifiers_demo();
    storage_duration_and_linkage();
    lvalues_rvalues_demo();

    /* Pointers & memory section */
    addresses_and_dereference();
    const_with_pointers();
    const_correctness_api_style();

    /* Operators section */
    arithmetic_demo();
    division_truncation_demo();
    integer_promotion_demo();
    sign_extension_demo();
    bitwise_demo();
    shifts_demo();
    logical_short_circuit_demo();
    

    /* Arrays section */
    array_basics();
    array_traversal();
    pointer_arithmetic_demo();
    multi_dimensional_demo();
    sizeof_vs_decay_demo();
    arrays_functions_demo();

    /* Strings section */
    cstring_basics();
    strlen_vs_sizeof_demo();
    literal_and_mutation_demo();
    safe_copy_concat_demo();
    memmove_vs_memcpy_demo();
    tokenize_demo();
    compare_demo();
    snprintf_format_demo();

    puts("=== done ===");

    return 0;
}
