#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int *global;

int main()
{
    int *local = NEW(int);
    global = local;

    printf("%p %p", local, global);

    return 0;
}
