#include <stdio.h>
int main(void)
{
    int L , M;
    int i = 0 , j = 0 , k = 0;
    scanf("%d %d",&L,&M);
    int all[L+1];
    for ( k = 0 ; k < L+1 ; k++)
    {
        all[k] = 1;
    }
    
    int num[M][2];
    for ( i = 0 ; i < M ; i++)
    {
        for ( j = 0 ; j < 2 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for ( i = 0 ; i < M ; i++)
    {
        for ( k = num[i][0] ; k <= num[i][1] ; k++)
        {
            all[k] = 0;
        }
    }
    int temp = 0;
    for ( k = 0 ; k < L+1 ; k++)
    {
        if (all[k] == 1)
        {
            temp++;
        }
    }
    printf("%d",temp);


    system("pause");
    return 0;
}