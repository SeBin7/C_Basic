#include <stdio.h>
#include "practice_examples.h"

void integer_types(void) {
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647L;
    long long lln = 123451234512345L;

    printf("short 변수 출력 : %d\n", sh);
    printf("int 변수 출력 : %d\n", in);
    printf("long 변수 출력 : %ld\n", ln);
    printf("long long 변수 출력 : %lld\n", lln);
}

void unsigned_overflow(void) {
    unsigned int a = 4294967295; 
    printf("a = %u\n", a);

    a = a + 1;  
    printf("a+1 = %u\n", a);

    a = a - 1;  
    printf("a-1 = %u\n", a);
}

void floating_precision(void) {
    float ft = 1.234567890123456789;      
    double db = 1.234567890123456789;     

    printf("float형 변수의 값   : %.20f\n", ft);
    printf("double형 변수의 값  : %.20lf\n", db);
}

void division_remainder(void) {
    double apple;
    int banana;
    int orange;

    apple = 5.0 / 2.0;
    banana = 5 / 2;
    orange = 5 % 2;

    printf("apple : %.1lf\n", apple);
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);
}

void pre_post_example(void) {
    int a = 5, b = 5;
    int pre, post;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("증감 연산 후 초깃값 a = %d, b = %d\n", a, b);
    printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);

    return 0;
}

void short_circuit(void) {
    int i = 0, j = 0, x, y;
    x = 0 && (i = j = 999);
    printf("%d %d %d\n", i, j, x);
    y = 1 || (i = ++j);
    printf("%d %d %d\n", i, j, y);
}

void sizeof_example(void) {
    int a = 10;
    double b = 3.4;

    printf("int형 변수의 크기 : %d\n", (int)sizeof(a));
    printf("double형 변수의 크기 : %d\n", (int)sizeof(b));
    printf("정수형 상수의 크기 : %d\n", (int)sizeof(10));
    printf("수식의 결괏값의 크기 : %d\n", (int)sizeof(1.5 + 3.4));
    printf("char 자료형의 크기 : %d\n", (int)sizeof(char));
}

void comma_operator(void) {
    int a = 10, b = 20;
    int res;

    res = (++a, ++b);

    printf("a:%d, b:%d\n", a, b);
    printf("res:%d", res);
 }

void ternary_operator(void) {
    int a = 10, b = 20;
    int res;

    res = (a > b) ? a : b;

    printf("큰 값:%d\n", res);
}

void bit_operator(void) {
    int a = 10;
    int b = 12;

    printf("a & b : %d\n", a & b);
    printf("a ^ b : %d\n", a ^ b);
    printf("a | b : %d\n", a | b);
    printf("~a : %d\n", ~a);
    printf("a << 1 : %d\n", a << 1);
    printf("a >> 2 : %d\n", a >> 2);

}

void ifelse_example(void) {
    int a = 0, b = 0;

    if (a > 0) {
        b = 1;
    }
    else if (a == 0) {
        b = 2;
    }
    else {
        b = 3;
    }

    printf("b : %d\n", b);

 }

void switch_example(void) {
    int rank = 2, m = 0;

    switch (rank) {
    case 1:
        m = 300;
        break;
    case 2:
        m = 200;
        break;
    case 3:
        m = 100;
        break;
    default:
        m = 10;
        break;
    }
}

void for_example(void) {
    int Line, i, j, k, x;
    //printf("정수 입력: ");
    //scanf("%d", &Line);
    Line = 5;
    for (i = 0; i < Line; i++) {
        x = Line - i;
        for (j = 0; j < i; j++) printf(" ");
        for (k = 0; k < x; k++) printf("*");
        printf("\n");
    }
    printf("---------------\n");
    for (i = 0; i < Line + 1; i++) {
        x = Line - i;
        for (j = 0; j < i; j++) printf("*");
        for (k = 0; k < x; k++) printf(" ");
        printf("\n");
    }
    printf("---------------\n");
    for (i = 0; i < Line + 1; i++) {
        x = Line - i;
        for (j = 0; j < x; j++) printf("*");
        for (k = 0; k < i; k++) printf(" ");
        printf("\n");
    }
    printf("---------------\n");
    for (i = 0; i < Line + 1; i++) {
        x = Line - i;
        for (j = 0; j < x; j++) printf(" ");
        for (k = 0; k < i; k++) printf("*");
        printf("\n");
    }
    printf("---------------\n");
    for (i = 0; i < Line; i++) {
        x = Line - i;
        if (i < 3) {
            for (j = 3; j < x; j++) printf(" ");
            for (k = 0; k < i; k++) printf("*");
            for (j = 0; j < i + 1; j++) printf("*");
            for (k = 0; k < x; k++) printf(" ");
            printf("\n");
        }        
    }
    printf("---------------\n");
    for (i = 0; i < Line + 1; i++) {
        x = Line - i;
        if (i < 3) {
            for (j = 0; j < i; j++) printf(" ");
            for (k = 0; k < x-3; k++) printf("*");
            for (j = 0; j < x-2; j++) printf("*");
            for (k = 0; k < i; k++) printf(" ");
            printf("\n");
        }
    }
    printf("---------------\n");
    for (i = 0; i < Line; i++) {
        x = Line - i;
        if (i < 2) {
            for (j = 3; j < x; j++) printf(" ");
            for (k = 0; k < i; k++) printf("*");
            for (j = 0; j < i + 1; j++) printf("*");
            for (k = 0; k < x; k++) printf(" ");
            printf("\n");
        }
    }
    for (i = 0; i < Line; i++) {
        x = Line - i;
        if (i < 3) {
            for (j = 0; j < i; j++) printf(" ");
            for (k = 0; k < x - 3; k++) printf("*");
            for (j = 0; j < x - 2; j++) printf("*");
            for (k = 0; k < i; k++) printf(" ");
            printf("\n");
        }
    }
}