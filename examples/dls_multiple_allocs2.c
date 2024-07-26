#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int d;
    struct Node* n;
    struct Node* b;
};

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    struct Node* h = NULL;
    struct Node* t = NULL;

    for (int i = 0; i < 10; i++) {
        struct Node *p = NEW(struct Node);
        p->n = NULL;
        p->d = 0;
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }

    struct Node* m = t;

    for (int i = 0; i < 10; i++) {
        struct Node *p = NEW(struct Node);
        p->n = NULL;
        p->d = 0;
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }

    struct Node* a = h;
    struct Node* b = t;
    struct Node* c = a->n;
    struct Node* d = b->b;

    printf("%p %p %p %p", a, b, c, d);

    return 0;
}
