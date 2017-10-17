#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int one_to_nine(int num)
{
    if (num == 48)
    {
        return 0;
    }
    else if (num == 49)
    {
        return 1;
    }
    else if (num == 50)
    {
        return 2;
    }
    else if (num == 51)
    {
        return 3;
    }
    else if (num == 52)
    {
        return 4;
    }
    else if (num == 53)
    {
        return 5;
    }
    else if (num == 54)
    {
        return 6;
    }
    else if (num == 55)
    {
        return 7;
    }
    else if (num == 56)
    {
        return 8;
    }
    else if (num == 57)
    {
        return 9;
    }
}
void obtain_num(char* str , int* num)
{
    int i = 0 , j = 0;
    for ( i = 0 ; i < 51 ; i++)
    {
        if ( 48 <= str[i] && str[i] <= 57 )
        {
            num[j] = one_to_nine(str[i]);
            j++;
        }
        else
        {
            num[j] = -1;
            j++;
        }
    }
}
int cal_num(int* num)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int result = 0;
    for (i = 0 ; i < 50 ; i++)
    {
        if ( num[i] != -1)
        {
            for ( j = i ; ; j++)
            {
                if ( num[j] == -1 )
                {
                    break;
                }
                k++;
            }
            int temp_num[k];
            for ( j = i ; j < i+k ; j++)
            {
                temp_num[l] = num[j];
                num[j] = -1;
                l++;
            }
            int temp_k = k;
            for ( l = 0 ; l < k ; l++)
            {
                result += temp_num[l] * pow(10,temp_k - 1);
                temp_k--;
            }
            printf("%d ",result);
            return result;
        }
    }
}
int main(void)
{
    char str[51];
    gets(str);
    int num[50];
    obtain_num(str , num);
    int result = 0;
    int i = 0;
    for ( i = 0 ; i < 50 ; i++)
    {
        result += cal_num(num);
    }
    printf("%d",result);


    system("pause");
    return 0;
}