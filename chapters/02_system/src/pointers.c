#include <stdio.h>
#include "pointers.h"

static int add(int a, int b) { return a + b; }

void demo_pointer_basics(void) {
    int x = 5;
    int* p = &x;
    printf("=== [Pointer Basics] ===\n");
    printf(" x=%d, &x=%p, p=%p, *p=%d\n", x, (void*)&x, (void*)p, *p);
    printf("\n");
}

void demo_array_pointer_relation(void) {
    int arr[4] = { 10, 20, 30, 40 };
    int* p = arr; // arr decays to &arr[0]
    printf("=== [Array & Pointer] ===\n");
    printf(" arr=%p, &arr[0]=%p, p=%p\n", (void*)arr, (void*)&arr[0], (void*)p);
    printf(" p[0]=%d, *(p+1)=%d\n", p[0], *(p + 1));
    printf("\n");
}

void demo_function_pointer(void) {
    int (*fp)(int, int) = &add;
    printf("=== [Function Pointer] ===\n");
    printf(" add ptr=%p, add(2,3) via fp=%d\n", (void*)fp, fp(2, 3));
    printf("\n");
}

// =========================
// 1) Fill pre-allocated buffer (T*) — modify contents only
// =========================
void fill_buf(char* buf, size_t size) {
    // Caller must guarantee "size" is sufficient.
    const char* msg = "hello";
    size_t need = strlen(msg) + 1; // +1 for '\0'
    if (need <= size) {
        strcpy(buf, msg);
    }
    else {
        // Truncate safely
        if (size) {
            size_t copy = size - 1;
            memcpy(buf, msg, copy);
            buf[copy] = '\0';
        }
    }
}

// =========================
// 2) Allocate a new buffer
//    (A) return new pointer (T*)
//    (B) out-param (T**) updates caller's pointer
// =========================
char* alloc_buf_return(size_t size) {
    // Factory-style: return the new pointer (NULL on failure)
    return (char*)malloc(size);
}

int alloc_buf_outparam(char** pp, size_t size) {
    // Out-param: assign into caller's pointer
    char* p = (char*)malloc(size);
    if (!p) return -1;
    *pp = p;
    return 0;
}

// =========================
// 3) Resize / Release with out-param (T**)
// =========================
int resize_buf(char** pp, size_t new_size) {
    // Safe pattern: only commit to *pp on success
    char* np = (char*)realloc(*pp, new_size);
    if (!np && new_size != 0) {
        // Realloc failed; *pp remains unchanged
        return -1;
    }
    *pp = np; // Commit update (np may be NULL if new_size==0)
    return 0;
}

void release_buf(char** pp) {
    // Free and nullify caller's pointer to avoid dangling usage
    if (pp && *pp) {
        free(*pp);
        *pp = NULL;
    }
}

// =========================
// 4) Linked list head update
//    (A) return new head (T*)
//    (B) out-param: update head in-place (T**)
// =========================
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* push_front_ret(Node* head, int v) {
    Node* n = (Node*)malloc(sizeof(*n));
    if (!n) return head; // Keep old head on failure
    n->value = v;
    n->next = head;
    return n; // Caller must assign: head = push_front_ret(head, v);
}

int push_front_out(Node** head, int v) {
    Node* n = (Node*)malloc(sizeof(*n));
    if (!n) return -1;
    n->value = v;
    n->next = *head;
    *head = n; // Update caller's head in-place
    return 0;
}

void print_list(const Node* head, const char* tag) {
    printf("%s: [", tag);
    const Node* cur = head;
    while (cur) {
        printf("%d", cur->value);
        cur = cur->next;
        if (cur) printf(" -> ");
    }
    printf("]\n");
}

void free_list(Node** head) {
    Node* cur = *head;
    while (cur) {
        Node* nx = cur->next;
        free(cur);
        cur = nx;
    }
    *head = NULL;
}

void demo_pointer_patterns(void) {
    printf("=== (1) Fill pre-allocated buffer (T*) ===\n");
    {
        char local[16] = { 0 };
        fill_buf(local, sizeof(local));   // content-only update
        printf("local = \"%s\"\n\n", local);
    }

    printf("=== (2) Allocate new buffer (return vs out-param) ===\n");
    {
        // (A) Return a new pointer
        char* p = alloc_buf_return(32);
        if (!p) { perror("alloc_buf_return"); return; }
        strcpy(p, "via return()");
        printf("p = \"%s\"\n", p);
        free(p);

        // (B) Out-param: update caller's pointer
        char* q = NULL;
        if (alloc_buf_outparam(&q, 32) != 0) {
            perror("alloc_buf_outparam"); return;
        }
        strcpy(q, "via out-param");
        printf("q = \"%s\"\n\n", q);
        free(q);
    }

    printf("=== (3) Resize / Release with out-param (T**) ===\n");
    {
        char* buf = NULL;

        // allocate via out-param
        if (alloc_buf_outparam(&buf, 8) != 0) { perror("alloc"); return; }
        strcpy(buf, "hi");
        printf("buf(before) = \"%s\"\n", buf);

        // grow
        if (resize_buf(&buf, 64) != 0) { perror("resize grow"); release_buf(&buf); return; }
        strcat(buf, " + grown");
        printf("buf(grown)  = \"%s\"\n", buf);

        // shrink
        if (resize_buf(&buf, 16) != 0) { perror("resize shrink"); release_buf(&buf); return; }
        printf("buf(shrink) = \"%s\"\n", buf);

        // release (also sets buf = NULL)
        release_buf(&buf);
        printf("buf(after release) = %p\n\n", (void*)buf);
    }

    printf("=== (4) Linked list head update (return vs out-param) ===\n");
    {
        // (A) Return new head
        Node* headA = NULL;
        headA = push_front_ret(headA, 3);
        headA = push_front_ret(headA, 2);
        headA = push_front_ret(headA, 1);
        print_list(headA, "list A (return)");
        free_list(&headA);

        // (B) Out-param: update head in-place
        Node* headB = NULL;
        push_front_out(&headB, 30);
        push_front_out(&headB, 20);
        push_front_out(&headB, 10);
        print_list(headB, "list B (out-param)");
        free_list(&headB);
        printf("\n");
    }

    printf("Done.\n");
}