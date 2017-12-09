#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N , R , result = 0;
    int num[1024] = {0};
    int book[1024] = {0};
    scanf("%d %d", &N, &R);
    int i;
    for ( i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    for ( i = 1 ; i < N ; i++)
    {
        book[i] = num[i]-num[i-1];
    }
    int temp = 0 , j;
    for ( i = 1 ; i < N ; )
    {
        for ( j = i+1 ; temp <= R ; )
        {
            if ( j > N-1) break;
            temp += book[j];
            j++;
        }
        j--;
        temp -= book[j-1];
        if (book[i] <= R && temp <= R)
        {
            result += 1;
            i += j;
        }
        else if (book[i] < R && book[i+1] > R)
        {
            result += 1;
            i += 1;
        }
        else
        {
            result += 1;
            i += 1;
        }
    }
    printf("%d",result);

    system("pause");
    return 0;
}