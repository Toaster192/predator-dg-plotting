#include <stdlib.h>

struct Node {
    int d;
    int* d2;
    struct Node* n;
    struct Node* b;
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
	if (i == 5){
		p->d2 = NEW(int);
	} else {
		p->d2 = NULL;
	}
        p->b = t;
        if (NULL == h)
            h = p;
        else
            t->n = p;
        t = p;
    }
    while (--i);

    return 0;
}
