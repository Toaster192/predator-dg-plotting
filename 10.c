#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int* id (int* x) { return x; }

int* foo() {
	int* a = NEW(int);
	a = id(a);
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
    printf("%p %p", x, y);

    return 0;
}
