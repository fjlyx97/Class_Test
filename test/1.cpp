#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *p , *q;
    p = q;
    *p = *q;

    system("pause");
    return 0;
}