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
    __VERIFIER_plot(NULL);
    struct Node *h = NEW(struct Node);
    __VERIFIER_plot(NULL);
    struct Node *t = NEW(struct Node);
    __VERIFIER_plot(NULL);
    h->n = t;
    __VERIFIER_plot(NULL);

    return 0;
}
