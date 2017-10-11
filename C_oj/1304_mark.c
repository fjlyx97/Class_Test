#include <stdio.h>
#include <stdlib.h>
int addNum(int , int);
int main(void)
{
    int n , num = 0;
    int temp = 0;
    int result = 0;
    int i;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; i++)
    {
        result += addNum(i,temp);
    }
    printf("%d",result);

    system("pause");
    return 0;
}
int addNum(int num , int result)
{
    if ( num == 1 || num == 2)
    {
        return 0;
    }
    else if ( num == 3)
    {
        return 1;
    }
    num = addNum(num-1,result) + addNum(num-2,result) + addNum(num-3,result);
    return num;
}