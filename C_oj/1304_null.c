#include <stdio.h>
#include <stdlib.h>
int addNum(int);
int main(void)
{
    int n , result;
    scanf("%d",&n);
    result = addNum(n);


    system("pause");
    return 0;
}
int addNum(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    return (addNum(num-1) + addNum(num-2) + addNum(num-3));
}