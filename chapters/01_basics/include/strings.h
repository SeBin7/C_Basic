#ifndef STRINGS_H
#define STRINGS_H

void cstring_basics(void);          // char array vs literal, null-termination
void strlen_vs_sizeof_demo(void);   // length vs storage size pitfalls
void literal_and_mutation_demo(void);// UB warning: modifying literals vs array ok
void safe_copy_concat_demo(void);   // snprintf / strnlen+memcpy patterns
void memmove_vs_memcpy_demo(void);  // overlapping copy difference
void tokenize_demo(void);           // strtok demo
void compare_demo(void);            // strcmp semantics
void snprintf_format_demo(void);    // bounded formatting & truncation check

#endif
