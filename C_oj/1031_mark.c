#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    int i;
    int result = 0;
    for (i = 1;i < x ; i++)
    {
        if (x % i == 0)
        {
            result += i;
        }
    }
    if (result == x)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    system("pause");
    return 0;
}