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

    __VERIFIER_plot(NULL);
    for (int i = 0; i < 5; i++) {
        struct Node *p = NEW(struct Node);
        __VERIFIER_plot(NULL);
        p->n = NULL;
        p->d = i;
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }
    __VERIFIER_plot(NULL);

    return 0;
}
