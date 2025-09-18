#include <stdio.h>
#include <stddef.h>   // offsetof
#include "structs_enums.h"

/* ----- 1) Enums ----- */
void enum_demo(void) {
    Mode m = MODE_RUN;

    printf("[enum_demo]\n");
    printf("MODE_INIT=%d, MODE_RUN=%d, MODE_STOP=%d\n", MODE_INIT, MODE_RUN, MODE_STOP);

    switch (m) {
    case MODE_INIT: puts("current mode: INIT"); break;
    case MODE_RUN: puts("current mode: RUN");  break;
    case MODE_STOP: puts("current mode: STOP"); break;
    default:        puts("unknown mode");       break;
    }
    puts("");
}

/* ----- 1b) Bit-flags (enum as mask) ----- */
void flags_demo(void) {
    Perm p = (Perm)(F_READ | F_WRITE);

    printf("[flags_demo]\n");
    printf("init   p=0x%02X (R=%d W=%d X=%d)\n", p, !!(p & F_READ), !!(p & F_WRITE), !!(p & F_EXEC));

    p = (Perm)(p | F_EXEC);      // add EXEC
    p = (Perm)(p & ~F_READ);     // remove READ

    printf("after  p=0x%02X (R=%d W=%d X=%d)\n\n", p, !!(p & F_READ), !!(p & F_WRITE), !!(p & F_EXEC));
}

/* ----- 2) Struct layout / padding / alignment ----- */
static Record scale_copy(Record r, double k) { r.value *= k; return r; }
static void   scale_inplace(Record* r, double k) { if (r) r->value *= k; }

void struct_layout_demo(void) {
    Record r = { .id = 7, .value = 3.14, .name = "sensor" };

    printf("[struct_layout_demo]\n");
    printf("sizeof(Record)=%zu, _Alignof(Record)=%zu\n",
        sizeof(Record), (size_t)_Alignof(Record));
    printf("offsetof(id)=%zu, offsetof(value)=%zu, offsetof(name)=%zu\n",
        offsetof(Record, id), offsetof(Record, value), offsetof(Record, name));
    printf("r: id=%d, value=%.2f, name=%s\n", r.id, r.value, r.name);

    Record r2 = r;       // by-value copy
    r2.value = 2.00;     // does not affect r
    printf("copy r2.value=%.2f (r.value still=%.2f)\n\n", r2.value, r.value);
}

/* ----- 3) Bit-fields ----- */
void bitfield_demo(void) {
    StatusBits st = { 0 };
    st.ready = 1;
    st.error = 0;
    st.code = 42 & 0x3F;

    printf("[bitfield_demo]\n");
    printf("sizeof(StatusBits)=%zu, ready=%u, error=%u, code=%u\n\n",
        sizeof(st), st.ready, st.error, st.code);
}

/* ----- 4) Packed struct (alignment caveat) ----- */
void packed_struct_demo(void) {
    PackedHeader h = { .id = 0xAB, .len = 0x1234, .flags = 0x00C0FFEEu };

    printf("[packed_struct_demo]\n");
    printf("sizeof(PackedHeader)=%zu (packed)\n", sizeof(PackedHeader));
    printf("id=0x%02X, len=0x%04X, flags=0x%08X\n\n", h.id, h.len, h.flags);
}

/* ----- 5) Tagged union ----- */
static void print_variant(const Variant* v) {
    switch (v->tag) {
    case V_INT:    printf("Variant: int=%d\n", v->u.i); break;
    case V_DOUBLE: printf("Variant: double=%.3f\n", v->u.d); break;
    case V_STR:    printf("Variant: str=\"%s\"\n", v->u.s); break;
    default:       printf("Variant: unknown tag\n"); break;
    }
}

void tagged_union_demo(void) {
    Variant a = { .tag = V_INT,    .u.i = 42 };
    Variant b = { .tag = V_DOUBLE, .u.d = 3.5 };
    Variant c = { .tag = V_STR,    .u.s = "hello" };

    printf("[tagged_union_demo]\n");
    print_variant(&a);
    print_variant(&b);
    print_variant(&c);
    puts("");
}

/* ----- 6) Pass struct by value vs by pointer ----- */
void pass_struct_by_value_demo(void) {
    Record r = { .id = 1, .value = 10.0, .name = "node-A" };

    printf("[pass_struct_by_value_demo]\n");
    Record cpy = scale_copy(r, 2.0);   // copy changed
    scale_inplace(&r, 3.0);            // original changed
    printf("orig r.value=%.2f, copy cpy.value=%.2f\n\n", r.value, cpy.value);
}

/* ----- 7) Designated initializers (struct/array) ----- */
void designated_init_demo(void) {
    Record r = { .name = "cpu0", .id = 3, .value = 1.25 };

    int a[8] = { [0] = 1,[3] = 7,[7] = 9 };  // others default to 0

    printf("[designated_init_demo]\n");
    printf("r={id=%d, value=%.2f, name=%s}\n", r.id, r.value, r.name);
    printf("a: ");
    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) printf("%d ", a[i]);
    puts("\n");
}
