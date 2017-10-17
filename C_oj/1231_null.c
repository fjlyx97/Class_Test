#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i , j , k;
    int result = 0;
    for ( i = 1 ; i < 10 ; i++ )
    {
        for ( j = 1 ; j < 10 ; j++)
        {
            for ( k = 1 ; k < 10 ; k++)
            {
                if (( i + j + k ) % 2 == 1 && i != j && i != k && j != k )
                {
                    result += 1;
                }
            }
        }
    }
    printf("%d",result);
    //最终答案需要除以A33，即重复的情况。
    system("pause");
    return 0;
}