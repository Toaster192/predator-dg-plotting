#include <verifier-builtins.h>
#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int* id (int* x) { return x; }

int* foo() {
	int* a = NEW(int);
	a = id(a);
        __VERIFIER_plot(NULL);
	return a;
}
int* bar() {
	int* b = NEW(int);
	b = id(b);
	return b;
}
int main()
{
    int* x = foo();
    int* y = bar();
    __VERIFIER_plot(NULL);
    printf("%p %p", x, y);

    return 0;
}
