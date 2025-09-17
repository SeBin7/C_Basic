#include <stdio.h>
#include "structs_enums.h"

typedef enum { COLOR_RED=1, COLOR_GREEN=2, COLOR_BLUE=3 } Color;

typedef struct {
    const char* name;
    int age;
    Color fav;
} Person;

void demo_structs_enums(void) {
    Person p = {"Alice", 30, COLOR_GREEN};

    printf("[structs/enums] name=%s, age=%d, fav=%d\n", p.name, p.age, p.fav);
}

