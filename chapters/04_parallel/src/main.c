
#include "pthreads_demo.h"

#include "process_ipc.h"

#include "openmp_demo.h"

#include "cuda_intro.h"



int main(void) {

    demo_pthreads_demo();

    demo_process_ipc();

    demo_openmp_demo();

    demo_cuda_intro();

    return 0;

}

