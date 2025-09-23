#include <stdio.h>
#include <stdint.h>
#include "bitops.h"

void demo_bitwise_ops(void) {
    /* Use hex instead of binary literals for MSVC C compatibility */
    uint8_t a = 0xAA; /* 1010 1010 */
    uint8_t b = 0xCC; /* 1100 1100 */
    printf("=== [Bitwise Ops] ===\n");
    printf(" a=0x%02X, b=0x%02X\n", a, b);
    printf(" a & b = 0x%02X\n", (uint8_t)(a & b));
    printf(" a | b = 0x%02X\n", (uint8_t)(a | b));
    printf(" a ^ b = 0x%02X\n", (uint8_t)(a ^ b));
    printf(" ~a    = 0x%02X\n", (uint8_t)(~a));
    printf(" a<<1  = 0x%02X, a>>1 = 0x%02X\n", (uint8_t)(a << 1), (uint8_t)(a >> 1));
    printf("\n");
}

void demo_bitmask_flags(void) {
    enum { R = 1 << 0, W = 1 << 1, X = 1 << 2 }; // rwx flags
    unsigned flags = 0;
    printf("=== [Bitmask Flags] ===\n");
    flags |= R | W;   // set R and W
    printf(" set R|W -> flags=0x%X\n", flags);
    if (flags & R) printf("  R enabled\n");
    if (flags & X) printf("  X enabled (should not print)\n");
    flags ^= W;       // toggle W
    printf(" toggle W -> flags=0x%X\n\n", flags);
}
