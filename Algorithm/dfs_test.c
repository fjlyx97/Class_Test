#include <stdio.h>
#include <stdlib.h>
void dfs(int step ,int* num , int* book, int* a)
{
    int i = 0;
    if (step == 10)
    {
        if (num[1]*100+num[2]*10+num[3] + num[4]*100+num[5]*10+num[6] == num[7]*100+num[8]*10+num[9])
        {
            *a += 1;
            printf("%d%d%d+%d%d%d=%d%d%d\n",num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
        }
        return;
    }
    for ( i = 1 ; i < 10 ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            num[step] = i;
            dfs(step+1,num,book,a);
            book[i] = 0;
        }
    }
    return;
}
int main(void)
{
    int num[10] = {0};
    int book[10] = {0};
    int a = 0;
    dfs(1,num,book,&a);
    printf("%d",a);


    system("pause");
    return 0;
}