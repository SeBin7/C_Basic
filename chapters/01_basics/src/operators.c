#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include "operators.h"

/* Basic arithmetic and a quick precedence reminder */
void arithmetic_demo(void) {
    int a = 7, b = 3;
    int add = a + b;
    int sub = a - b;
    int mul = a * b;
    int div_ = a / b;   // integer division
    int mod = a % b;

    printf("[arithmetic_demo]\n");
    printf("a=%d, b=%d\n", a, b);
    printf("a+b=%d, a-b=%d, a*b=%d, a/b=%d, a%%b=%d\n", add, sub, mul, div_, mod);

    // Precedence: * / % > + -
    int expr = 2 + 3 * 4 - 5; // = 2 + 12 - 5 = 9
    printf("expr (2 + 3*4 - 5) = %d\n\n", expr);
}

/* C integer division truncates toward zero for signed types */
void division_truncation_demo(void) {
    int x1 = 7, y1 = 3;
    int x2 = -7, y2 = 3;
    int x3 = 7, y3 = -3;

    printf("[division_truncation_demo]\n");
    printf(" 7 /  3 = %d,  7 %%  3 = %d\n", x1 / y1, x1 % y1);
    printf("-7 /  3 = %d, -7 %%  3 = %d\n", x2 / y2, x2 % y2);
    printf(" 7 / -3 = %d,  7 %% -3 = %d\n\n", x3 / y3, x3 % y3);
    // Standard guarantees: (a/b)*b + a%b == a, and / truncates toward zero.
}

/* Integer promotions: 'char' and 'short' become 'int' in expressions */
void integer_promotion_demo(void) {
    signed char  sc = -10;   // typically 8-bit
    unsigned char uc = 250;  // 250 fits in unsigned char
    short        ss = -300;
    unsigned short us = 60000;

    int  sum1 = sc + uc;   // both promoted to int before addition
    int  sum2 = ss + us;   // both promoted (usual arithmetic conversions)
    // Note: exact rules can choose 'unsigned int' if ranges require, but here we just print results.

    printf("[integer_promotion_demo]\n");
    printf("sc=%d, uc=%u, ss=%d, us=%u\n", sc, uc, ss, us);
    printf("sc + uc (promoted to int) = %d\n", sum1);
    printf("ss + us (promoted)        = %d\n\n", sum2);
}

/* Sign extension when converting small signed types to larger signed types */
void sign_extension_demo(void) {
    signed char  sc_neg = (signed char)0xF6; // -10 on two's complement (0b11110110)
    unsigned char uc_val = 0xF6;             // 246

    int sc_to_int = (int)sc_neg;            // sign-extended (likely -10)
    int uc_to_int = (int)uc_val;            // value 246

    printf("[sign_extension_demo]\n");
    printf("sc_neg raw 0x%02X -> as signed char = %d\n", (unsigned)(unsigned char)sc_neg, sc_neg);
    printf("sc_neg -> int (sign-extended) = %d\n", sc_to_int);
    printf("uc_val 0x%02X -> int (zero-extended) = %d\n\n", (unsigned)uc_val, uc_to_int);
}

/* Bitwise operators with binary literals (GCC/Clang extension 0bxxxx) */
void bitwise_demo(void) {
    unsigned x = 0b10110100u; // 0xB4
    unsigned y = 0b01011110u; // 0x5E

    printf("[bitwise_demo]\n");
    printf("x=0x%02X, y=0x%02X\n", x, y);
    printf("x & y = 0x%02X\n", (x & y));
    printf("x | y = 0x%02X\n", (x | y));
    printf("x ^ y = 0x%02X\n", (x ^ y));
    printf("~x    = 0x%02X\n", (unsigned)(~x & 0xFFu)); // mask for display of 8 low bits
    printf("x<<2  = 0x%02X, y>>1 = 0x%02X\n\n", (x << 2) & 0xFFu, (y >> 1) & 0xFFu);
}

/*
 * Shifts summary:
 *  - Left shift on unsigned is modulo 2^N, defined if shift count < width and no overflow of promoted type.
 *  - Right shift on unsigned is logical (zero-fill).
 *  - Right shift on signed negative is implementation-defined (arithmetic vs logical).
 *  - Shifting a negative value left or shifting by >= width is undefined behavior.
 * For didactic safety, we demonstrate with uint32_t and only non-problematic signed values.
 */
void shifts_demo(void) {
    uint32_t ux = 0x00F0U;   // 0000 0000 0000 0000 0000 0000 1111 0000
    uint32_t ul = ux << 4;   // left shift (defined)
    uint32_t ur = ux >> 4;   // logical right shift (zero-fill)

    int32_t  sx_pos = 0x000000F0; // positive signed
    int32_t  sr_pos = sx_pos >> 2; // right shift of positive is well-defined: implementation uses arithmetic == logical here

    int32_t  sx_neg = -16;        // negative signed
    int32_t  sr_neg = sx_neg >> 2; // IMPLEMENTATION-DEFINED (likely arithmetic shift on two's complement)

    printf("[shifts_demo]\n");
    printf("ux=0x%08X, ux<<4=0x%08X, ux>>4=0x%08X\n", ux, ul, ur);
    printf("sx_pos=0x%08X, sx_pos>>2=0x%08X\n", (uint32_t)sx_pos, (uint32_t)sr_pos);
    printf("sx_neg=%d (0x%08X), sx_neg>>2 (impl-defined) = %d (0x%08X)\n\n",
        sx_neg, (uint32_t)sx_neg, sr_neg, (uint32_t)sr_neg);
}

/* Short-circuit behavior of && and || */
void logical_short_circuit_demo(void) {
    int counter = 0;

    bool a = (0 && (++counter)); // left is false ¡æ right not evaluated
    bool b = (1 || (++counter)); // left is true  ¡æ right not evaluated

    printf("[logical_short_circuit_demo]\n");
    printf("a (0 && ++counter) -> %d, b (1 || ++counter) -> %d, counter=%d\n\n",
        a ? 1 : 0, b ? 1 : 0, counter);
}
