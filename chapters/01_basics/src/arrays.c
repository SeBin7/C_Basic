#include <stdio.h>
#include <stddef.h>
#include "arrays.h"

/* --- internal helpers (not exposed in header) --- */
static size_t sum_array(const int* a, size_t n) {
	size_t s = 0;
	for (size_t i = 0; i < n; ++i) s += (size_t)a[i];
	return s;
}

static void scale_array(int* a, size_t n, int k) {
	for (size_t i = 0; i < n; ++i) a[i] *= k;
}


/* Parameter declared as 'int a[]' is identical to 'int *a' in function parameter.
 * sizeof(a) here gives pointer size, not the original array size. */
static void use_array_param(int a[], size_t n) {
	printf("  [use_array_param] sizeof(param a)=%zu (pointer size)\n", sizeof(a));
	printf("  contents: ");
	for (size_t i = 0; i < n; ++i) printf("%d ", a[i]);
	puts("");
}

/* --- public demos --- */

void array_basics(void) {
    // Fixed-size compile-time arrays
    int a[5] = { 1,2,3,4,5 };        // full init
    int b[5] = { 1,2 };              // partial; rest zero-initialized
    int c[5] = { 0 };                // zero-initialization trick

    printf("[array_basics]\n");
    printf("sizeof(a)=%zu bytes (element count=%zu)\n", sizeof(a), sizeof(a) / sizeof(a[0]));
    printf("a: ");
    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) printf("%d ", a[i]);
    puts("");

    printf("b: ");
    for (size_t i = 0; i < sizeof(b) / sizeof(b[0]); ++i) printf("%d ", b[i]);
    puts("");

    printf("c: ");
    for (size_t i = 0; i < sizeof(c) / sizeof(c[0]); ++i) printf("%d ", c[i]);
    puts("\n");
}

void array_traversal(void) {
    int arr[5] = { 10, 20, 30, 40, 50 };
    printf("[array_traversal]\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("arr[%zu]=%d @%p\n", i, arr[i], (void*)&arr[i]);
    }
    puts("");
}

void pointer_arithmetic_demo(void) {
    int arr[4] = { 1, 2, 3, 4 };
    int* p = arr; // decay to &arr[0]
    printf("[pointer_arithmetic_demo]\n");
    printf("*p=%d, *(p+1)=%d, p[2]=%d, 2[p]=%d (same as p[2])\n\n",
        *p, *(p + 1), p[2], 2[p]);
}

void multi_dimensional_demo(void) {
    int m[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    printf("[multi_dimensional_demo]\n");
    printf("&m[0][0]=%p, &m[0][1]=%p, &m[0][2]=%p\n",
        (void*)&m[0][0], (void*)&m[0][1], (void*)&m[0][2]);
    printf("&m[1][0]=%p, &m[1][1]=%p, &m[1][2]=%p\n\n",
        (void*)&m[1][0], (void*)&m[1][1], (void*)&m[1][2]);
    // Addresses increase sequentially in row-major order.
}

void sizeof_vs_decay_demo(void) {
    int arr[6] = { 1,2,3,4,5,6 };
    size_t N = sizeof(arr) / sizeof(arr[0]);

    printf("[sizeof_vs_decay_demo]\n");
    printf("sizeof(arr)=%zu bytes, element count=%zu\n", sizeof(arr), N);
    use_array_param(arr, N); // here parameter 'a' is a pointer (sizeof gives pointer size)
    puts("");
}

void arrays_functions_demo(void) {
    int data[5] = { 2,4,6,8,10 };
    size_t N = sizeof(data) / sizeof(data[0]);

    printf("[arrays_functions_demo]\n");
    size_t s1 = sum_array(data, N);     // const-correct read
    printf("sum_array = %zu\n", s1);

    scale_array(data, N, 3);            // in-place write
    printf("after scale x3: ");
    for (size_t i = 0; i < N; ++i) printf("%d ", data[i]);
    puts("");

    size_t s2 = sum_array(data, N);
    printf("sum_array (after scale) = %zu\n\n", s2);
}