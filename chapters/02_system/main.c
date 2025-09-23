#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memory_model.h"
#include "pointers.h"
#include "bitops.h"
#include "build_link.h"

static void usage(const char* prog) {
    printf("Usage:\n");
    printf("  %s memory     # memory model demos\n", prog);
    printf("  %s pointers   # pointer demos\n", prog);
    printf("  %s bitops     # bit operations demos\n", prog);
    printf("  %s build      # build & link demos\n", prog);
    printf("\n");
}

int main(int argc, char** argv) {
    const char* prog = (argc > 0 ? argv[0] : "system_demos");
    if (argc < 2) {
        usage(prog);
        return 0;
    }

    if (strcmp(argv[1], "memory") == 0) {
        demo_segments();
        demo_stack_heap();
        demo_struct_padding();
        dump_proc_maps_short(20);
        return 0;
    }

    if (strcmp(argv[1], "pointers") == 0) {
        demo_pointer_basics();
        demo_array_pointer_relation();
        demo_function_pointer();

        // NEW: double-pointer practical patterns (4-in-1 demo)
        demo_pointer_patterns();

        return 0;
    }

    if (strcmp(argv[1], "bitops") == 0) {
        demo_bitwise_ops();
        demo_bitmask_flags();
        return 0;
    }

    if (strcmp(argv[1], "build") == 0) {
        demo_build_stages();
        demo_external_symbol();
        return 0;
    }

    usage(prog);
    return 0;
}
