#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cal(int num)
{
    int my_num = num;
    int c = 0; //进位
    int * save_num = (int*)malloc(sizeof(int) * 1000000);
    int * result = (int*)malloc(sizeof(int) * 1000000);
    memset(save_num,0,sizeof(save_num));
    save_num[0] = 1;
    int i = 0 , j = 0;
    while (num)
    {
        save_num[j] = num % 10;
        num /= 10;
        j++;
    }
    int temp = 0;
    int in_num = 0;
    int k = 0;
    for ( i = my_num-1 ; i > 0 ; i-- )
    {
        in_num = i;
        j = 0;
        while (in_num)
        {
            result[k] += c;
            c = 0;
            temp = in_num % 10;
            for ( j = 0 ; ; j++)
            {
                result[k] += c;
                temp *= save_num[j];
                if (temp >= 10)
                {
                    c = temp / 10;
                    temp = temp % 10;
                }
                result[k] += temp;
                k++;
            }
            in_num /= 10;
            j++;
        }
    }
}
int main(void)
{
    int T;
    int num;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&num);
        cal(num);
    }

    system("pause");
    return 0;
}