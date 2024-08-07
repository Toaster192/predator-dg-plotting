#include <verifier-builtins.h>
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

    for(int i = 0; i < 8; i++){
        struct Node *p = NEW(struct Node);
        p->n = NULL;
        p->d = i; 
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }

    struct Node *a = h;
    struct Node *b = h->n;
    struct Node *c = t->b;
    struct Node *d = h->n->b;
    struct Node *e = NEW(struct Node);

    __VERIFIER_plot(NULL);
    printf("%p %p %p %p %p", a, b, c, d, e);

    free(t);
    free(c);
    free(b);
    free(a);
    free(e);

    return 0;
}
