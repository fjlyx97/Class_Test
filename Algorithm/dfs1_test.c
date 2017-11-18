#include <stdio.h>
#include <stdlib.h>
int num[10] , book[10] , total = 0;
void dfs(int step)
{
    int i;
    if (step == 10)
    {
        if (num[1]*100+num[2]*10+num[3] + num[4]*100+num[5]*10+num[6] == num[7]*100+num[8]*10+num[9])
        {
            total++;
            printf("%d%d%d+%d%d%d=%d%d%d\n",num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
        }
        return;
    }
    for ( i = 1 ; i <= 9 ; i++)
    {
        if (book[i] == 0)
        {
            num[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return;
}
int main(void)
{
    dfs(1);
    printf("total=%d",total/2);

    system("pause");
    return 0;
}