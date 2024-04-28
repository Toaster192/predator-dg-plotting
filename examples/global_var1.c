#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int *foo;

int main()
{
    int *a = NEW(int);
    foo = a;

    printf("%p %p", a, foo);

    return 0;
}
