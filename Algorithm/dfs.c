#include <stdio.h>
#include <stdlib.h>
void dfs(int step , int n , int* book , int* num , int* total)
{
    if (step == n+1)
    {
        //printf("%d%d%d+%d%d%d=%d%d%d\n",num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
        if (num[1]*100+num[2]*10+num[3] + num[4]*100+num[5]*10+num[6] == num[7]*100+num[8]*10+num[9])
        {
            (*total)++;
            printf("%d%d%d+%d%d%d=%d%d%d\n",num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
        }
        return;
    }
    int i = 0;
    for (i = 1 ; i <= n ; i++ )
    {
        if ( book[i] == 0 )
        {
            num[step] = i;
            book[i] = 1;
            dfs(step+1,n,book,num,total);
            book[i] = 0;
        }
    }
    return;
}
int main(void)
{
    int num[10];
    int book[10] = {0};
    int total = 0;
    dfs(1,9,book,num,&total);
    printf("total is %d.",total);
    system("pause");
    return 0;
}