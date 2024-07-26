#include <assert.h>
#include <stdlib.h>

#define NEW(type) (type *) malloc(sizeof(type))

int *id (int *x) { return x; }

int main(void)
{
    int *a = NEW(int);
    int *b = NEW(int);
    int *c = NEW(int);

    a = id(a);
    b = id(b);
    c = id(c);

    assert(a != b);
    
    return 0;
}
