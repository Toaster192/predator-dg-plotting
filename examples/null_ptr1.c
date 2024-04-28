#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *a = NEW(int);
    int *b = NULL;
    int **fp;
    fp = &a;
    fp = &b;

    printf("%p %p %p", a, b, *fp);

    return 0;
}
