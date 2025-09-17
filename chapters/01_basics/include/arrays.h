#ifndef ARRAYS_H
#define ARRAYS_H

void array_basics(void);           // declaration, init patterns, zero-init with {0}
void array_traversal(void);        // index + address printing
void pointer_arithmetic_demo(void);// arr decay, p[i] == *(p+i)
void multi_dimensional_demo(void); // row-major layout addresses
void sizeof_vs_decay_demo(void);   // sizeof(array) vs sizeof(param)
void arrays_functions_demo(void);  // const-correct sum, in-place scale

#endif
