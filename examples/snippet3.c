#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *a, *b, **p;
    a = NEW(int);
    b = NEW(int);
    p = &a;

    printf("%p %p %p", a, b, *p);
    return 0;
}
