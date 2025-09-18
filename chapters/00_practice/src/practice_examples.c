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

    printf("int�� ������ ũ�� : %d\n", (int)sizeof(a));
    printf("double�� ������ ũ�� : %d\n", (int)sizeof(b));
    printf("������ ����� ũ�� : %d\n", (int)sizeof(10));
    printf("������ �ᱣ���� ũ�� : %d\n", (int)sizeof(1.5 + 3.4));
    printf("char �ڷ����� ũ�� : %d\n", (int)sizeof(char));
}

void pointer_basic_example(void) {
    int a, b;
    int* pa, *pb;

    pa = &a;
    *pa = 10;


    printf("�����ͷ� a �� ��� : %d\n", *pa);
    printf("������� a �� ��� : %d\n", a);
}

void pointer_address_size_example(void) {
    char ch;
    int in;
    double db;

    char* pc = &ch;
    int* pi = &in;
    double* pd = &db;

    printf("char�� ������ �ּ� ũ�� : %d\n", (int)sizeof(&ch));
    printf("int�� ������ �ּ� ũ�� : %d\n", (int)sizeof(&in));
    printf("double�� ������ �ּ� ũ�� : %d\n", (int)sizeof(&db));

    printf("char * �������� �ּ� ũ�� : %d\n", (int)sizeof(pc));
    printf("int * �������� �ּ� ũ�� : %d\n", (int)sizeof(pi));
    printf("double * �������� �ּ� ũ�� : %d\n", (int)sizeof(pd));

    printf("char * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", (int)sizeof(*pc));
    printf("int * �����Ͱ� ����Ű�� ���� ũ�� : %d\n", (int)sizeof(*pi));
    printf("double * �����Ͱ� ����Ű�� ���� ũ�� : %d\n", (int)sizeof(*pd));
}
void swap(int* pa, int* pb);

void pointer_example2(void) {
    int a = 10, b = 20;

    swap(&a, &b);
    printf("a:%d, b:%d\n", a, b);

}

void swap(int* pa, int* pb) {
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void pointer_array_example(void) {
    int ary[3] = { 10, 20, 30 };
    int* pa = ary;
    int i;

    printf("�迭�� �� : ");
    for (i = 0; i < 3; i++) {
        printf("%d ", *pa);
        pa++;
    }

    return 0;
}

void pointer_example2(void) {
    int ary[5] = { 10, 20, 30, 40, 50 };
    int* pa = ary;
    int* pb = pa + 3;

    printf("pa : %u\n", pa);
    printf("pb : %u\n", pb);

    pa++;
    printf("pb - pa : %u\n", pb - pa);

    printf("�տ� �ִ� �迭 ����� �� ��� : ");
    if (pa < pb) printfA("%d\n", *pa);
    else printf("%d\n", *pb);
}