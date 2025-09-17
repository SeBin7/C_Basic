#ifndef OPERATORS_H
#define OPERATORS_H

void arithmetic_demo(void);             // +, -, *, /, % and precedence reminder
void division_truncation_demo(void);    // integer division truncates toward zero
void integer_promotion_demo(void);      // char/short -> int promotions in expressions
void sign_extension_demo(void);         // cast signed small types -> int (observe sign)
void bitwise_demo(void);                // &, |, ^, ~ with 0b literals
void shifts_demo(void);                 // <<, >> for unsigned vs signed (notes on UB)
void logical_short_circuit_demo(void);  // &&, || short-circuit evaluation

#endif
