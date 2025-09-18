#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

/* Small struct to demonstrate return-by-value */
struct Pair { int a; int b; };

/* Basic arithmetic ops (also used with function pointers) */
int add(int a, int b);
int sub(int a, int b);

/* Pass-by-value vs pass-by-pointer (output parameter pattern) */
void pass_by_value(int x);
void pass_by_pointer(int* x);
void swap_via_pointer(int* a, int* b);

/* Return small struct by value */
struct Pair make_pair(int a, int b);
/* Backward-compatible name (used earlier in main.c) */
struct Pair return_struct_demo(int x, int y);

/* Const-correct array input and out-parameters */
size_t sum_const_array(const int* arr, size_t n);
void   fill_sequence(int* dst, size_t n, int start);

/* Function pointer usage */
typedef int (*op_fn)(int, int);
int apply_op(op_fn f, int x, int y);

/* Recursion vs iteration */
int factorial_recursive(int n);
int factorial_iterative(int n);

/* Header-only tiny helper (internal linkage) */
static inline int max2(int a, int b) { return (a > b) ? a : b; }

#endif