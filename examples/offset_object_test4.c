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
    struct Node *f = NEW(struct Node);
    struct Node **p = &((f)->n);
    *p = (NEW(struct Node));
    struct Node *h = *p-16;

    return 0;
}