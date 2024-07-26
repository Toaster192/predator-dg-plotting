#include <stdio.h>

int main()
{
    int x, y, *p, *q, **r, **s;
    p = &x;
    r = &p;
    q = &y;
    s = &q;
    r = s;

    printf("%d %d %p %p %p %p", x, y, p, q, r, s);
    return 0;
}
