#include <stdio.h>
#include <stdlib.h>
int judge(int* save_num , int num );
int main(void)
{
    int save_num[10000];
    save_num[0] = 2;
    int i = 0;
    int num = 2;
    int result = 1;
    int j = 1;
    for ( num = 3 ; num <= 10000 ; num++)
    {
        for ( i = 2 ; i < num ; i++)
        {
            if ( num % i == 0 )
            {
                result = 0;
                break;
            }
        }
        if ( 1 == result )
        {
            save_num[j] = num;
            j++;
        }
        result = 1;
    }
    //1228
    int input_num[1024];
    for (i = 0 ; ; i++)
    {
        scanf("%d",&input_num[i]);
        if ( input_num[i] == 0)
        {
            break;
        }
    }
    for (i = 0 ; ; i++)
    {
        if ( input_num[i] == 0)
        {
            break;
        }
        judge(save_num , input_num[i]);
    }

    

    system("pause");
    return 0;
}
int judge(int* save_num , int num )
{
    int i = 0 , j = 0;
    for ( i = 1228 ; i >= 0 ; i--)
    {
        for ( j = 0 ; j <= 1228 ; j++)
        {
            if (save_num[i] + save_num[j] == num)
            {
                printf("%d=%d+%d\n",num,save_num[j],save_num[i]);
                return 0;
            }
        }
    }
}