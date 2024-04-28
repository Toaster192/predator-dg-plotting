#include <verifier-builtins.h>
#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *a = NEW(int);
    int *b = NEW(int);
    int *c = a;

    __VERIFIER_plot(NULL);
    printf("%p %p %p", a, b, c);

    return 0;
}
