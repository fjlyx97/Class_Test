#include <stdio.h>
#include <stdlib.h>
void dfs(int step , int n , int* book , int* save)
{
    int i , j ;
    if ( step == n+1)
    {
        for ( j = 1 ; j <= n ; j++)
        {
            printf("%d ",save[j]);
        }
        printf("\n");
    }
    for ( i = 1 ; i <= n ; i++)
    {
        
        if (book[i] == 0)
        {
            save[step] = i;
            book[i] = 1;
            dfs(step+1,n,book,save);
            book[i] = 0;
        }
    }
    return;
}
int main(void)
{
    int n;
    int book[10] = {0};       //标记是否使用过扑克牌
    int save[10] = {0};       //标记存放的扑克牌
    scanf("%d",&n);

    dfs( 1, n, book, save);

    system("pause");
    return 0;
}