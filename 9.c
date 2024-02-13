#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int* foo[10] = {};

    foo[2] = NEW(int);

    printf("%p %p", foo[0], foo[2]);

    return 0;
}
