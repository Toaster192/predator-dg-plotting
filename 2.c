#include <verifier-builtins.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* n;
    struct Node* b;
};

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    struct Node *h = NEW(struct Node);
    struct Node *t = NEW(struct Node);
    h->n = t;
    __VERIFIER_plot(NULL);
    printf("%p %p", h, t);

    return 0;
}
