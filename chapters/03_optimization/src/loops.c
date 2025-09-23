
#include <stdio.h>

#include "loops.h"



void demo_loops(void) {

    volatile int s=0;

    for (int i=0;i<100000;i++) s+=i;

    printf("[opt] loop demo sum=%d (check perf with different flags)\n", s);

}

