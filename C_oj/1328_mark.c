#include <stdio.h>
#include <stdlib.h>
int Judge(int , int*);
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[n];
    int i = 0;
    for (i = 0 ; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    int money_num = 0;
    int* p = &money_num;
    for (i = 0 ; i < n; i++)
    {
        Judge( num[i] , p);
    }
    printf("%d",money_num);

    system("pause");
    return 0;
}
int Judge(int num , int * money_num)
{
    if ( num >= 100)
    {
        *money_num += 1;
        num -= 100;
        Judge(num,money_num);
    }
    else if ( num < 100 && num >= 50 )
    {
        *money_num += 1;
        num -= 50;
        Judge(num,money_num);
    }
    else if ( num < 50 && num >= 10 )
    {
        *money_num += 1;
        num -= 10;
        Judge(num,money_num);
    }
    else if ( num < 10 && num >= 5 )
    {
        *money_num += 1;
        num -= 5;
        Judge(num,money_num);
    }
    else if ( num < 5 && num >= 2 )
    {
        *money_num += 1;
        num -= 2;
        Judge(num,money_num);
    }
    else if ( num < 2 && num >= 1 )
    {
        *money_num += 1;
        num -= 1;
        Judge(num,money_num);
    }
}