#include <stdio.h>
#include <stdlib.h>
int fun(int , int);
int main(void)
{
    int t;
    scanf("%d",&t);
    int num[t][2];
    int i = 0 , j = 0;
    int result = 0;
    for (i = 0 ; i < t ; i++)
    {
        for ( j = 0 ; j < 2 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for (i = 0 ; i < t ; i++)
    {
        for ( j = 0 ; j < 2 ; j++)
        {
            result += fun(num[i][j]);
        }
    }
    printf("%d",result);
    
    system("pause");
    return 0;
}
int fun(int m,int n)  //m个苹果放在n个盘子中共有几种方法
{
    if(m==0||n==1)  //因为我们总是让m>=n来求解的，所以m-n>=0,所以让m=0时候结束，如果改为m=1，
        return 1;    //则可能出现m-n=0的情况从而不能得到正确解    
    if(n>m)
        return fun(m,m);
    else
        return fun(m,n-1)+fun(m-n,n);
}
