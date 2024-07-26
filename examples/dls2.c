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

    for (int i = 0; i < 5; i++) {
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

    return 0;
}
