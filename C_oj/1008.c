#include <stdio.h>
#include <stdlib.h>
int Judge(int);
int main(void)
{
    int i = 0;
    Judge(672);
    int num[701];
    num[700] = -1;
    int j = 0;
    for (i = 1 ; i <= 700 ; i++)
    {
        num[j] = Judge(i);
        j++;
    }
    int max_flower = num[0];
    int flower_num = 0 ;
    int num_put[700];
    int k = 0;
    for ( i = 0 ; i < 700 ; i++)
    {
        if (num[i] < num[i+1] && num[i+1] > max_flower )
        {
            max_flower = num[i+1];
        }
        if (num[i] != -1)
        {
            flower_num += 1;
            num_put[k] = num[i];
            k++;
        }
    }
    printf("%d\n",max_flower);
    printf("%d\n",flower_num);
    for (i = 0 ; i < flower_num ; i++)
    {
        printf("%d ",num_put[i]);
    }

    system("pause");
    return 0;
}
int Judge(int num)
{
    int i , result = 0;
    for ( i = 1 ; i <= num ; i++)
    {
        if ( num % i == 0)
        {
            if ( i < num / i)
            {
                result += i + num / i;
            }
        }
    }
    if (result % num == 0)
    {
        return num;
    }
    else
    {
        return -1;
    }
}