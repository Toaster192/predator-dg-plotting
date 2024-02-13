#include <verifier-builtins.h>
#include <stddef.h>
#include <stdlib.h>

int main()
{
    //struct Node *p = NEW(struct Node);
    __VERIFIER_plot(NULL);
    int *baz = malloc(sizeof(*baz) * 3);
    __VERIFIER_plot(NULL);
    int *baz2 = baz;
    __VERIFIER_plot(NULL);

    return 0;
}
