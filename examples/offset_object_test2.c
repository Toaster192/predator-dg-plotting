#include <verifier-builtins.h>
#include <stddef.h>
#include <stdlib.h>

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

    struct Node *p = NEW(struct Node);
    p->n = NULL;
    p->d = 0;
    p->b = t;
    if (NULL == h)
        h = p;
    else
        t->n = p;
    t = p;

    struct Node* f = p->n;

    return 0;
}
