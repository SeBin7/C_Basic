#ifndef STRUCTS_ENUMS_H
#define STRUCTS_ENUMS_H

#include <stddef.h>
#include <stdint.h>

/* 1) Enums & bit-flags */
typedef enum { MODE_INIT = 0, MODE_RUN = 1, MODE_STOP = 2 } Mode;

typedef enum {
    F_NONE = 0,
    F_READ = 1u << 0,
    F_WRITE = 1u << 1,
    F_EXEC = 1u << 2
} Perm;

/* 2) Struct layout */
typedef struct {
    int         id;
    double      value;
    const char* name;
} Record;

/* 3) Packed struct (demo) */
#pragma pack(push, 1)
typedef struct {
    uint8_t  id;
    uint16_t len;
    uint32_t flags;
} PackedHeader;
#pragma pack(pop)

/* 4) Bit-fields */
typedef struct {
    unsigned ready : 1;
    unsigned error : 1;
    unsigned code : 6;  /* 0..63 */
} StatusBits;

/* 5) Tagged union (variant) */
typedef enum { V_INT, V_DOUBLE, V_STR } Tag;
typedef struct {
    Tag tag;
    union {
        int         i;
        double      d;
        const char* s;
    } u;
} Variant;

/* Demos */
void enum_demo(void);
void flags_demo(void);
void struct_layout_demo(void);
void bitfield_demo(void);
void packed_struct_demo(void);
void tagged_union_demo(void);
void pass_struct_by_value_demo(void);
void designated_init_demo(void);

#endif
