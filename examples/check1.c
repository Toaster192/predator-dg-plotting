#include <assert.h>
#include <stdlib.h>

#define NEW(type) (type *) malloc(sizeof(type))

int check(int a){
	return a == 0;
}

int *id (int *x) { return x; }

int main(void)
{
    int *a = NEW(int);
    int *b = NEW(int);

    *a = 20;
    *b = 10;

    a = id(a);
    b = id(b);

    *b = 0;

    check(*a);
    
    return 0;
}
