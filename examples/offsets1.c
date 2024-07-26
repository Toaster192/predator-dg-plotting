#include <verifier-builtins.h>
#include <stddef.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(40*sizeof(int));

    int (*array)[40];
    int **t;
    int a = 6;
    int b;
    scanf("%d", &b);
    t = &p;
    array = p;

    p[2];
    p[4500];
    t[0][2];
    (*array)[20];
    array[0][10];
    array[1][-10];
    (*array)[40];
    array[2][-10];
    (*array)[100];

    p[a];
    p[b];

    return 0;
}
