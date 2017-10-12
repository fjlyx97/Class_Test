#include <stdio.h>
#include <stdlib.h>
void Judge(int);
int main(void)
{
    int num[1024];
    int i = 0;
    for ( i = 0 ; ; i++)
    {
        scanf("%d",&num[i]);
        if (num[i] == 0)
        {
            break;
        }
    }
    for ( i = 0 ; ; i++)
    {
        if (num[i] == 0)
        {
            break;
        }
        Judge(num[i]);
    }
    system("pause");
    return 0;
}
void Judge(int num)
{
    int num_temp = 0;
    while ( num > 0)
    {
        num_temp +=  num % 10;
        num = num / 10;
    }
    if ( num_temp >= 10 )
    {
        Judge(num_temp);
    }
    else
    {
        printf("%d\n",num_temp);
    }
}