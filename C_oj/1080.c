#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    unsigned int a , num;
    scanf("%d %d", &a, &num);
    unsigned int result , temp;
    result = 0;
    temp = 0;
    int i;
    for (i = 0 ; i < num; i++)
    {
        temp = a + temp * 10;
        result += temp;
    }
    printf("%d",result);



    system("pause");
    return 0;
}