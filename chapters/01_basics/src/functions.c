#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* ----- basic arithmetic ops ----- */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

/* ----- pass-by-value vs pass-by-pointer ----- */
void pass_by_value(int x) {
	x += 100;
	printf("[pass_by_value] local x=%d (caller uanaffected)\n", x);
}

void pass_by_pointer(int *x) {
	if (!x) return;
	*x += 100;
	printf("[pass_by_pointer] *x updated (caller will observe)\n");
}

void swap_via_pointer(int* a, int* b) {
	if (!a || !b) return;
	int tmp = *a;
	*a = *b;
	*b = tmp;
	printf("[swap_via_pointer] swapped values\n");
}

/* ----- struct return by value ----- */
struct Pair make_pair(int a, int b) {
	struct Pair p = { a, b };
	return p; // small structs are fine to return by value in C
}

/* Back-compat alias for earlier demos */
struct Pair return_struct_demo(int x, int y) {
	return make_pair(x, y);
}

/* ----- const-correct array input / output buffer patterns ----- */
size_t sum_const_array(const int* arr, size_t n) {
	size_t s = 0;
	for (size_t i = 0; i < n; ++i) s += (size_t)arr[i];
	printf("[sum_const_array] n=%zu, sum=%zu\n", n, s);
	return s;
}

void fill_sequence(int* dst, size_t n, int start) {
	/* dst is an out-parameter (writable), caller must ensure capacity>=n */
	for (size_t i = 0; i < n; ++i) dst[i] = start + (int)i;
	printf("[fill_sequence] filled %zu ints starting at %d\n", n, start);
}

/* ----- function pointer usage ----- */
int apply_op(op_fn f, int x, int y) {
	assert(f && "apply_op: function pointer must not be NULL");
	int r = f(x, y);
	printf("[apply_op] f(%d,%d) = %d\n", x, y, r);
	return r;
}

/* ----- recursion vs iteration ----- */
int factorial_recursive(int n) {
	/* naive recursive version (no overflow checks for brevity) */
	if (n <= 1) return 1;
	return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
	int acc = 1;
	for (int i = 2; i <= n; ++i) acc *= i;
	return acc;
}