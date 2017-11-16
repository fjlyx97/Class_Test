#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <math.h>
int main(void)
{
    int q[102] = {0,6,3,1,7,5,8,9,2,4} , head , tail;
    int i;
    head = 1;
    tail = 10;
    while ( head < tail )
    {
        printf("%d ",q[head]);
        head++;

        q[tail] = q[head];
        tail++;

        head++;
    }
    system("pause");
    return 0;
}