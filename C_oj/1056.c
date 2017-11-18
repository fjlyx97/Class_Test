#include <stdio.h>
#include <stdlib.h>
void dfs(int step , int* total , int* num , int M , int N)
{
    int i = 0;
    int temp = 0;
    if (step == N)
    {
        for ( i = 0 ; i < N ; i++)
        {
            temp += num[i];
        }
        if ( temp == M)
        {
            *total += 1;
        }
        return;
    }
    for ( i = 0 ; i <= M ; i++)
    {
        num[step] = i;
        dfs( step+1, total , num , M , N);
        num[step] = 0;
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    int M , N;      //M个苹果N个盘子
    scanf("%d %d",&M,&N);
    int total = 0;
    int num[N];
    dfs( 0, &total, num , M, N);
    printf("%d",total);

    system("pause");
    return 0;
}