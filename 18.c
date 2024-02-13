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

    free(foo[*(foo[0])]);
    free(foo[8]);

    return 0;
}
