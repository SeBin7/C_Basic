#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

/* 1) Basics: null-terminated C strings */
void cstring_basics(void) {
    char buf[] = "hello";          // modifiable array with space for '\0'
    const char* lit = "world";     // pointer to string literal (read-only)

    printf("[cstring_basics]\n");
    printf("buf=\"%s\" (len=%zu)\n", buf, strlen(buf));
    printf("lit=\"%s\" (len=%zu)\n\n", lit, strlen(lit));
}

/* 2) strlen vs sizeof: different meanings */
void strlen_vs_sizeof_demo(void) {
    char s1[] = "hi";              // {'h','i','\0'}  sizeof=3, strlen=2
    char s2[10] = "hi";            // storage=10, strlen=2, trailing zeros exist

    printf("[strlen_vs_sizeof_demo]\n");
    printf("s1: strlen=%zu, sizeof=%zu\n", strlen(s1), sizeof(s1));
    printf("s2: strlen=%zu, sizeof=%zu | bytes: ", strlen(s2), sizeof(s2));
    for (size_t i = 0; i < sizeof(s2); ++i) {
        unsigned char b = (unsigned char)s2[i];
        printf("%02X ", b);
    }
    puts("\n");
}

/* 3) Literal mutation is UB; array mutation is fine */
void literal_and_mutation_demo(void) {
    const char* p = "test";   // literal: read-only storage (modifying is UB)
    char a[] = "test";        // array: modifiable

    printf("[literal_and_mutation_demo]\n");
    printf("literal p=\"%s\"\n", p);
    // p[0] = 'T';            // DONT: undefined behavior
    a[0] = 'T';               // OK
    printf("array  a=\"%s\" (after a[0]='T')\n\n", a);
}

/* 4) Safe copy/concat patterns */
void safe_copy_concat_demo(void) {
    const char* s1 = "abc";
    const char* s2 = "defgh";
    char dst1[8];
    char dst2[8];

    /* Pattern A: snprintf (bounded + returns required length) */
    int n = snprintf(dst1, sizeof(dst1), "%s%s", s1, s2);
    bool truncated = (n < 0) || ((size_t)n >= sizeof(dst1));

    /* Pattern B: strnlen + memcpy, then manual NUL */
    const char* src = "ABCDEFG";
    size_t max_copy = sizeof(dst2) - 1; // leave room for '\0'
    size_t to_copy = strnlen(src, max_copy);
    memcpy(dst2, src, to_copy);
    dst2[to_copy] = '\0';

    printf("[safe_copy_concat_demo]\n");
    printf("dst1=\"%s\" (snprintf n=%d, truncated=%s)\n",
        dst1, n, truncated ? "yes" : "no");
    printf("dst2=\"%s\" (manual copy, to_copy=%zu)\n\n", dst2, to_copy);
}

/* 5) memcpy vs memmove (overlap handling) */
void memmove_vs_memcpy_demo(void) {
    char b1[8] = "abcdef";
    char b2[8] = "abcdef";

    /* Overlapping move: source [0..3] -> dest starting at 2 */
    memmove(b1 + 2, b1, 4);  // defined: memmove handles overlap
    b1[6] = '\0';            // ensure NUL (we copied 4 bytes onto positions 2..5)

    /* memcpy with overlap is undefined; we do NOT execute it.
       For demonstration, we only show a non-overlapping memcpy: */
    memcpy(b2, "123456", 6); // safe non-overlap
    b2[6] = '\0';

    printf("[memmove_vs_memcpy_demo]\n");
    printf("memmove overlap result : \"%s\"\n", b1); // expected "ababcd"
    printf("memcpy non-overlap     : \"%s\"\n\n", b2);
}

/* 6) Tokenization via strtok (modifies buffer) */
void tokenize_demo(void) {
    char line[] = "one,two;three four";
    const char* delims = ",; ";

    printf("[tokenize_demo]\n");
    for (char* tok = strtok(line, delims); tok != NULL; tok = strtok(NULL, delims)) {
        printf("token: \"%s\"\n", tok);
    }
    puts("");
}

/* 7) strcmp semantics: negative/zero/positive */
void compare_demo(void) {
    const char* a = "Apple";
    const char* b = "Banana";
    const char* c = "Apple";

    int ab = strcmp(a, b);
    int ac = strcmp(a, c);
    int ba = strcmp(b, a);

    printf("[compare_demo]\n");
    printf("strcmp(\"%s\",\"%s\") = %d  (a<b? %s)\n", a, b, ab, (ab < 0 ? "yes" : "no"));
    printf("strcmp(\"%s\",\"%s\") = %d  (equal? %s)\n", a, c, ac, (ac == 0 ? "yes" : "no"));
    printf("strcmp(\"%s\",\"%s\") = %d  (b>a? %s)\n\n", b, a, ba, (ba > 0 ? "yes" : "no"));
}

/* 8) Bounded formatting with truncation check */
void snprintf_format_demo(void) {
    char buf[10];
    int n = snprintf(buf, sizeof(buf), "[%d:%s]", 42, "ABCDEFG");

    bool truncated = (n < 0) || ((size_t)n >= sizeof(buf));
    printf("[snprintf_format_demo]\n");
    printf("buf=\"%s\" (n=%d, truncated=%s)\n\n", buf, n, truncated ? "yes" : "no");
}
