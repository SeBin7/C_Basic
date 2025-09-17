#include <stdio.h>
#include "pointers_memory.h"

/* Show addresses, pointers, and write-through via dereference */
void addresses_and_dereference(void) {
    int a = 10;
    int b = 20;
    int* p = &a;

    printf("[addresses_and_dereference]\n");
    printf("a=%d @%p\n", a, (void*)&a);
    printf("b=%d @%p\n", b, (void*)&b);
    printf("p (points to a)=%p, *p=%d\n", (void*)p, *p);

    *p = 99; // write through pointer
    printf("after *p=99 ¡æ a=%d, *p=%d\n\n", a, *p);
}

/* const pointer forms */
void const_with_pointers(void) {
    int x = 10;
    int y = 20;

    const int* ptr_to_const = &x; // cannot modify *ptr_to_const
    int* const const_ptr = &y;    // pointer itself is const

    printf("[const_with_pointers]\n");
    printf("x=%d, y=%d\n", x, y);

    // *ptr_to_const = 99; // ERROR
    ptr_to_const = &y;     // OK: can repoint

    *const_ptr = 77;       // OK: change target value
    // const_ptr = &x;     // ERROR: cannot repoint

    printf("after: x=%d, y=%d (y modified via const_ptr)\n\n", x, y);
}

/* API-style const-correctness: read-only vs writable view */
void const_correctness_api_style(void) {
    int data = 42;
    const int* read_only = &data; // consumer should not modify through this
    int* writable = &data;

    printf("[const_correctness_api_style]\n");
    printf("data=%d (read_only @%p, writable @%p)\n\n",
        data, (void*)read_only, (void*)writable);
}
