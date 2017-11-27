#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char str[N][101];
    int num[N];
    int i = 0 , j = 0;
    int k = 0;
    int temp = 0;
    for ( i = 0 ; i < N ; i++)
    {
        scanf("%s",&str[i][0]);
    }
    for ( i = 0 ; i < N ; i++)
    {
        temp = 0;
        for (j = 0 ; str[i][j] != '\0' ; j++)
        {
            temp += str[i][j];
        }
        num[k] = temp;
        k++;
    }
    int ans = 0;
    for ( i = 0 ; i < N ; i++)
    {
        ans ^= num[i];
    }
    int index;
    for ( i = 0 ; i < N ; i++)
    {
        if (ans == num[i])
        {
            index = i;
        }
    }
    printf("%s",str[index][0]);


    system("pause");
    return 0;
}