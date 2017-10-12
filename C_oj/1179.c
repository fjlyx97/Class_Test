#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , S , num;
    scanf("%d %d",&N , &S);
    num = N-S;
    int result;
    result = num * (N-1) * (N-2);
    printf("%d",result);

    system("pause");
    return 0;
}