#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num;
    scanf("%d",&num);
    int num_single = 0 , num_double = 0;
    int temp = 0;
    if (num == 0)
    {
        num_double++;
    }
    while (num)
    {
        temp = num % 10;
        if (temp % 2 == 0)
        {
            num_double++;
        }
        else
        {
            num_single++;
        }
        num /= 10;
    }
    printf("%d,%d",num_single,num_double);

    system("pause");
    return 0;
}