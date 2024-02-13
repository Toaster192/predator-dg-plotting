#include <stdlib.h>

struct Node {
    int d;
    struct Node* n;
};

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    struct Node* h = NULL;
    struct Node* t = NULL;

    int i = 10;
    do {
        struct Node *p = NEW(struct Node);
        p->n = NULL;
        p->d = i; 
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }
    while (--i);

    return 0;
}
