#include <stdio.h>
#include "practice_examples.h"

void integer_types(void) {
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647L;
    long long lln = 123451234512345L;

    printf("short ���� ��� : %d\n", sh);
    printf("int ���� ��� : %d\n", in);
    printf("long ���� ��� : %ld\n", ln);
    printf("long long ���� ��� : %lld\n", lln);
}

void unsigned_overflow(void) {
    unsigned int a = 4294967295; // UINT_MAX (32-bit ����)
    printf("a = %u\n", a);

    a = a + 1;  // overflow �߻� �� 0���� wrap-around
    printf("a+1 = %u\n", a);

    a = a - 1;  // �ٽ� �ִ밪���� wrap-around
    printf("a-1 = %u\n", a);
}

void floating_precision(void) {
    float ft = 1.234567890123456789;      // float: �� 7�ڸ� ���е�
    double db = 1.234567890123456789;     // double: �� 15~16�ڸ� ���е�

    printf("float�� ������ ��   : %.20f\n", ft);
    printf("double�� ������ ��  : %.20lf\n", db);
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

    printf("���� ���� �� �ʱ갪 a = %d, b = %d\n", a, b);
    printf("������: (++a) * 3 = %d, ������: (b++) * 3 = %d\n", pre, post);

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

    printf("int�� ������ ũ�� : %d\n", sizeof(a));
    printf("double�� ������ ũ�� : %d\n", sizeof(b));
    printf("������ ����� ũ�� : %d\n", sizeof(10));
    printf("������ �ᱣ���� ũ�� : %d\n", sizeof(1.5 + 3.4));
    printf("char �ڷ����� ũ�� : %d\n", sizeof(char));
}