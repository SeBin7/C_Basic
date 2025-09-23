#include <stdio.h>
#include "build_link.h"

// A global to be visible to the linker/symbol tools
int external_symbol = 12345;

void demo_build_stages(void) {
    printf("=== [Build & Link Pipeline] ===\n");
    printf(" Preprocess -> Compile -> Assemble -> Link\n");
    printf(" Use: -E, -S, -c, -o for each stage respectively.\n\n");
}

void demo_external_symbol(void) {
    extern int external_symbol;
    printf("=== [External Symbol] ===\n");
    printf(" external_symbol addr=%p, value=%d\n\n",
        (void*)&external_symbol, external_symbol);
}
