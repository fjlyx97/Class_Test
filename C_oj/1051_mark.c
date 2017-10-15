#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i = 0;
    for (i = 0 ; i < N ; i++)
    {
        num[i] = i+1;
    }
    int num_four = 0;
    int other_num = N;
    i = 0;
    while(1)
    {
        if (num[i] == 0)
        {
            if (i == N-1)
            {
                i = 0;
                continue;
            }
            else
            {
                i++;
                continue;
            }
        }
        ++num_four;
        if ( num_four == 4)
        {
            num[i] = 0;
            num_four = 0;
            other_num--;
        }
        if (other_num == 1)
        {
            break;
        }
        if ( i == N-1 )
        {
            i = -1;
        }
        i += 1;
    }
    for ( i = 0 ; ; i++)
    {
        if (num[i] != 0)
        {
            printf("%d",num[i]);
            break;
        }
    }


    system("pause");
    return 0;
}