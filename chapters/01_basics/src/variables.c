#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "variables.h"

/* Show literals, types, and common ranges via macros */
void literals_and_types(void) {
    /* Integer literals with suffixes */
    int          a = 42;          // decimal
    unsigned int b = 42u;         // unsigned
    long         c = 42l;         // long
    long long    d = 42ll;        // long long
    int          hex = 0x2A;      // 42 in hex
    int          oct = 052;       // 42 in octal
    int          bin = 0b101010;  // (GCC/Clang extension) 42 in binary

    /* Floating literals with suffixes */
    float  f = 3.14f;
    double g = 3.14;              // default is double
    long double h = 3.14L;

    /* Char and escape */
    char ch = 'A';
    char nl = '\n';

    printf("[literals_and_types]\n");
    printf("int=%d, unsigned=%u, long=%ld, long long=%lld\n", a, b, c, d);
    printf("hex=0x%X, octal=%o, bin=%d\n", hex, oct, bin);
    printf("float=%.2f, double=%.2f, long double=%.2Lf\n", f, g, h);
    printf("char='%c' nl='\\n'(=%d)\n", ch, nl);

    /* Show selected limits */
    printf("INT_MIN=%d, INT_MAX=%d, UINT_MAX=%u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("FLT_MIN=%e, FLT_MAX=%e, DBL_MAX=%e\n\n", FLT_MIN, FLT_MAX, DBL_MAX);
}

/* Initialization forms and scope/shadowing */
void initialization_and_scope(void) {
    int x = 10;          // initialized
    int y;               // uninitialized (indeterminate) in local scope
    y = 5;

    printf("[initialization_and_scope]\n");
    printf("x=%d, y=%d\n", x, y);

    {
        int x = 99;      // shadows outer x
        printf("inner block x=%d (shadowing outer x)\n", x);
    }

    printf("outer x still=%d\n\n", x);
}

/* Common format specifiers to avoid UB/mismatch */
void format_specifiers_demo(void) {
    int i = -12;
    unsigned u = 3000000000u;
    long l = 1234567890L;
    long long ll = 1234567890123LL;
    float f = 1.5f;
    double d = 2.5;
    char c = 'Z';
    const char* s = "hello";

    printf("[format_specifiers_demo]\n");
    printf("int: %%d=%d, unsigned: %%u=%u\n", i, u);
    printf("long: %%ld=%ld, long long: %%lld=%lld\n", l, ll);
    printf("float via %%f (promoted to double): %f\n", f);        // default arg promotion
    printf("double via %%f: %f\n", d);
    printf("char: %%c=%c, string: %%s=%s\n\n", c, s);
}

/* Storage duration & linkage overview (observable via static counter) */
static int internal_counter = 0;  // internal linkage (file-scope static)

void storage_duration_and_linkage(void) {
    static int calls = 0;         // static storage duration, retains value across calls
    calls++;
    internal_counter++;

    int auto_local = 123;         // automatic storage duration (stack)
    (void)auto_local;             // silence unused warning

    printf("[storage_duration_and_linkage]\n");
    printf("static local 'calls'=%d, file-scope static 'internal_counter'=%d\n\n",
        calls, internal_counter);
}

/* lvalues (assignable locations) vs rvalues (temporaries) */
int returns_temp(void) {
    return 7; // rvalue (temporary)
}

void lvalues_rvalues_demo(void) {
    int a = 1;
    int b = 2;

    printf("[lvalues_rvalues_demo]\n");
    a = b;           // OK: lvalue = rvalue
    // (a + b) = 5;  // ERROR: (a+b) is not an lvalue
    // returns_temp() = 10; // ERROR: rvalue on LHS

    printf("a=%d, b=%d\n\n", a, b);
}
