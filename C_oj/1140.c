#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    getchar();
    int num;
    int two_ten[1024];
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int result = 0;
    while (T--)
    {
        scanf("%d",&num);
        j = 0;
        temp = 0;
        result = 0;
        for ( i = 0 ; i < 1024 ; i++)
        {
            two_ten[i] = -1;
        }
        while (num)
        {
            two_ten[j] = num % 2;
            num /= 2;
            j++;
        }
        i = 0;
        k = j-1;
        if ( j % 2 == 0)
        {
            while ( i < k )
            {
                temp = two_ten[i];
                two_ten[i] = two_ten[k];
                two_ten[k] = temp;
                i++;
                k--;
            }
        }
        else
        {
            while ( i != k )
            {
                temp = two_ten[i];
                two_ten[i] = two_ten[k];
                two_ten[k] = temp;
                i++;
                k--;
            }
        }
        k = 0;
        for ( i = 0 ; i <= j-1 ; i++)
        {
            result += two_ten[i] * pow(2,k);
            k++;
        }
        printf("%d\n",result);
    }

    system("pause");
    return 0;
}