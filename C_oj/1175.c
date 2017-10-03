#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a , b;
    scanf("%d %d",&a,&b);
    int result = 0;
    int i;
    if (a > b)
    {
        for (i = b; i <= a; i++)
        {
            result += i;
        } 
    }
    else if (b > a)
    {
        for (i = a; i <= b; i++)
        {
            result += i;
        } 
    }
    else
    {
        result = a * 2;
    }

    printf("%d",result);

    system("pause");
    return 0;
}