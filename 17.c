#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *foo;

    foo = NEW(int);

    printf("%d", *foo);

    return 0;
}
