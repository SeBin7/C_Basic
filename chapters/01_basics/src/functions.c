#include <stdio.h>
#include "functions.h"

static int add(int x, int y) { return x + y; }

void demo_functions(void) {

    int s = add(10, 20);

    printf("[functions] add(10,20)=%d\n", s);

}

