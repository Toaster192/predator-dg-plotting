#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *foo[10];

    for(int i = 0; i < 5; i++){
	    foo[i] = NEW(int);
	    *(foo[i]) = i;
    }

    printf("%d %d %d", *(foo[0]), *(foo[1]), *(foo[8]));

    return 0;
}
