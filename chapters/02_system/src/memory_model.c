#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "memory_model.h"

// Globals to demonstrate .data and .bss
int g_init = 10;     // .data
int g_uninit;        // .bss

static int s_init = 100;  // .data
static int s_uninit;      // .bss

// Code pointer (text)
static void code_anchor(void) {}

// Return a pointer to a string literal (rodata)
static const char* ro_literal(void) {
    return "RODATA_LITERAL";
}

void demo_segments(void) {
    static int local_static_init = 1; // .data
    static int local_static_bss;      // .bss
    const char* ro = ro_literal();

    printf("=== [Segments Overview] ===\n");
    printf(" Code (text) addr      : %p (code_anchor)\n", (void*)&code_anchor);
    printf(" RODATA literal addr   : %p (\"%s\")\n", (void*)ro, ro);
    printf(" .data global addr     : %p (g_init)\n", (void*)&g_init);
    printf(" .bss  global addr     : %p (g_uninit)\n", (void*)&g_uninit);
    printf(" .data static addr     : %p (s_init)\n", (void*)&s_init);
    printf(" .bss  static addr     : %p (s_uninit)\n", (void*)&s_uninit);
    printf(" .data local static    : %p (local_static_init)\n", (void*)&local_static_init);
    printf(" .bss  local static    : %p (local_static_bss)\n", (void*)&local_static_bss);
    printf("\n");
}

void demo_stack_heap(void) {
    int stack_var = 42;
    int* heap_ptr = (int*)malloc(sizeof(int));
    if (!heap_ptr) {
        perror("malloc");
        return;
    }
    *heap_ptr = 777;

    printf("=== [Stack vs Heap] ===\n");
    printf(" Stack var addr : %p (stack_var)\n", (void*)&stack_var);
    printf(" Heap  ptr addr : %p (heap_ptr)\n", (void*)heap_ptr);
    printf(" *heap value    : %d\n", *heap_ptr);

    int another_stack = 0;
    printf(" Another stack var addr : %p\n", (void*)&another_stack);
    if ((char*)&another_stack < (char*)&stack_var) {
        printf(" (Stack appears to grow downward on this platform)\n");
    }
    else {
        printf(" (Stack appears to grow upward on this platform)\n");
    }
    free(heap_ptr);
    printf("\n");
}

/* --- struct padding demo --- */
struct A { char c; int i; };
struct B { char c1; char c2; int i; };
struct C { double d; char c; int i; };

static void print_struct_layout(const char* name, size_t sz,
    size_t off0, size_t off1, size_t off2,
    const char* f0, const char* f1, const char* f2)
{
    printf("=== [Struct %s] ===\n", name);
    printf(" sizeof(%s) = %zu\n", name, sz);
    printf(" %s offset = %zu\n", f0, off0);
    printf(" %s offset = %zu\n", f1, off1);
    if (f2) printf(" %s offset = %zu\n", f2, off2);
    printf("\n");
}

void demo_struct_padding(void) {
    print_struct_layout("A",
        sizeof(struct A),
        offsetof(struct A, c),
        offsetof(struct A, i),
        0, "c", "i", NULL);

    print_struct_layout("B",
        sizeof(struct B),
        offsetof(struct B, c1),
        offsetof(struct B, c2),
        offsetof(struct B, i), "c1", "c2", "i");

    print_struct_layout("C",
        sizeof(struct C),
        offsetof(struct C, d),
        offsetof(struct C, c),
        offsetof(struct C, i), "d", "c", "i");
}

/* --- /proc/self/maps short dump --- */
void dump_proc_maps_short(int max_lines) {
#if defined(_WIN32)
    (void)max_lines;
    printf("=== [/proc/self/maps] ===\n");
    printf(" Not available on Windows. Run on WSL/Linux to see memory maps.\n\n");
#else
    printf("=== [/proc/self/maps] (first %d lines) ===\n", max_lines);
    FILE* fp = fopen("/proc/self/maps", "r");
    if (!fp) {
        perror("fopen /proc/self/maps");
        return;
    }
    char buf[512];
    int count = 0;
    while (fgets(buf, sizeof(buf), fp) && count < max_lines) {
        fputs(buf, stdout);
        count++;
    }
    fclose(fp);
    printf("\n");
#endif
}

