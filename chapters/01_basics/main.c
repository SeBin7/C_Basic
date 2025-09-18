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

    /* Functions section */ 
    int v = 5;
    pass_by_value(v);
    printf("[caller] after pass_by_value: v=%d\n\n", v);

    pass_by_pointer(&v);
    printf("[caller] after pass_by_pointer: v=%d\n\n", v);

    int a = 1, b = 2;
    swap_via_pointer(&a, &b);
    printf("[caller] after swap_via_pointer: a=%d, b=%d\n\n", a, b);

    struct Pair p = return_struct_demo(10, 20);
    printf("[caller] return_struct_demo => (%d, %d)\n\n", p.a, p.b);

    int buf[6];
    fill_sequence(buf, 6, 100);
    size_t s = sum_const_array(buf, 6);
    printf("[caller] sum of buf = %zu\n\n", s);

    apply_op(add, 10, 3);
    apply_op(sub, 10, 3);

    printf("factorial_recursive(5)=%d, factorial_iterative(5)=%d\n\n",
        factorial_recursive(5), factorial_iterative(5));

    printf("max2(7, 12)=%d\n\n", max2(7, 12));

    /* Structs & Enums section */ 
    enum_demo();
    flags_demo();
    struct_layout_demo();
    bitfield_demo();
    packed_struct_demo();
    tagged_union_demo();
    pass_struct_by_value_demo();
    designated_init_demo();


    puts("=== done ===");

    return 0;
}
