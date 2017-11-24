#include <stdio.h>
#include <stdlib.h>
int fun(int number , int* num)
{
    int temp = 0;
    if (number / 10 == 0)
    {
        temp = num[number];
        return temp;
    }
    else
    {
        while (number)
        {
            temp += num[number % 10];
            number /= 10;
        }
    }
    return temp;
}
int main(void)
{
    int n;
    int num[10] = {6,2,5,5,4,5,6,3,7,6};
    int sum = 0;
    int total = 0;
    scanf("%d",&n);
    int a , b , c;
    for ( a = 0 ; a <= 1111 ; a++)
    {
        for (b = 0 ; b <= 1111 ; b++)
        {
            c = a + b;
            if (fun(a,num) + fun(b,num) + fun(c,num) == n-4)
            {
                total++;
            }
        }
    }
    printf("%d",total);
    system("pause");
    return 0;
}