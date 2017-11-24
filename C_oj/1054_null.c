#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void judge(int* num, int* primer, int n);
void dfs(int step , int n , int* num , int* book , int* primer);
void dfs(int step , int n , int* num , int* book , int* primer)
{
    if (num[1] != 0 && num[1] != 1)
    {
        return;
    }
    int i = 0;
    if (step == n+1)
    {
        judge(num,primer,n);
        return;
    }
    for (i = 1 ; i <= n ; i++)
    {
        if (book[i] == 0)
        {
            num[step] = i;
            book[i] = 1;
            dfs(step+1,n,num,book,primer);
            book[i] = 0;
        }
    }

    return;
}
void judge(int* num, int* primer,int n)
{
    int i = 0 , j = 0;
    int temp = 0;
    int status = 0;
    for ( i = 1 ; i < n ; i++)
    {
        temp = num[i] + num[i+1];
        if ( i == n-1 )
        {
            temp = num[i+1] + num[1];
        }
        for ( j = 0 ; j < 10 ; j++)
        {
            status = 0;
            if (temp == primer[j])
            {
                status = 1;
                break;
            }
        }
        if (status == 0)
        {
            break;
        }
    }
    if (status == 1)
    {
        for ( i = 1 ; i <= n ; i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
        return;
    }
}
int main(void)
{
    int primer[10] = {2,3,5,7,11,13,17,19,23,29};
    int n;
    scanf("%d",&n);

    int* book = (int*)malloc(sizeof(n+1));
    int* num = (int*)malloc(sizeof(n+1));
    int i = 0;
    for ( i = 0 ; i < n+1 ; i++)
    {
        book[i] = num[i] = 0;
    }

    dfs(1,n,num,book,primer);

    //free(book);
    //free(num);
    system("pause");
    return 0;
}