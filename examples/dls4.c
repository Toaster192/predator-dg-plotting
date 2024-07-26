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
    
    struct Node* a = h->n->n->n;
    struct Node* b = t->b->n->n;
    struct Node* c = t->b->n;
    struct Node* d = h->n->b;
    struct Node* e = h->n->n;

    printf("%d %d %d %d %d", a->d, b->d, c->d, d->d, e->d);

    return 0;
}
