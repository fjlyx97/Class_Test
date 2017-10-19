#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[10] = {0};
    int head = 0 , behind = 0;
    head = n / 10;
    behind = n % 10;
    

    int i = 0 , j = 0 , k = 0;
    for ( i = 0 ; i < 10 ; i++)
    {
        printf("%d\n",num[i]);
    }
    system("pause");
    return 0;
}