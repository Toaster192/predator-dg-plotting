#include <verifier-builtins.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a, b;
    int *p, *q;
    __VERIFIER_plot(NULL);
    p = &a;
    __VERIFIER_plot(NULL);
    q = &b;
    __VERIFIER_plot(NULL);
    q = p;
    __VERIFIER_plot(NULL);
    p = &b;
    __VERIFIER_plot(NULL);
    printf("%d, %d", *p, *q);
    __VERIFIER_plot(NULL);

    return 0;
}
