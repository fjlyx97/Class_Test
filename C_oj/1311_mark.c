#include <stdio.h>
#include <stdlib.h>
/*边界问题很重要，需要设置status和flag来判断边界问题*/
int main(void)
{
    int N , R;
    scanf("%d %d",&N,&R);
    int num[N];
    int i;
    int ans = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    int temp , j , flag , k , status;
    for ( i = 0 ; i < N ; )
    {
        flag = 0;
        status = 1;
        for ( j = i+1 ; j < N ; j++)
        {
            temp = num[j] - num[i];
            flag++;
            if (temp > R )
            {
                status = 0;
                break;
            }
        }
        if (flag == 1 && status == 0)
        {
            i += 1;
        }
        if (status == 1)
        {
            ans++;
            break;
        }
        else
        {
            flag = 0;
            i = j-1;
            for ( k = i+1 ; k < N ; k++)
            {
                temp = num[k]-num[i];
                flag++;
                if (temp > R)
                {
                    break;
                }
            }
            if (flag == 1)
            {
                i = i+1;
            }
            else
            {
                i = k;
            }
        }
        ans++;
    }
    printf("%d",ans);
    system("pause");
    return 0;
}