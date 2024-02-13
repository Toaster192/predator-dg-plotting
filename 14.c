#include <stdlib.h>
#include <stdio.h>

struct Node {
    int* a;
    int* b;
    int* c;
    int* d;
    int* e;
    int* f;
    int* g;
    int* h;
    int* i;
    int* j;
    int* k;
    int* l;
    int* m;
    int* n;
    int* o;
    int* p;
    int* q;
    int* r;
    int* s;
    int* t;
    int* u;
    int* v;
    int* w;
    int* z;
};

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    struct Node foo;
    foo.a = NEW(int);
    foo.q = NEW(int);
    foo.z = NEW(int);

    printf("%p %p %p", foo.a, foo.q, foo.z);

    return 0;
}
