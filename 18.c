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
        p->d = 1; 
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }

    __VERIFIER_plot(NULL);
    printf("%p %p", h, t);

    return 0;
}
