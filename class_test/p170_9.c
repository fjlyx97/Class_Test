#include <stdio.h>
#include <stdlib.h>
void num_to_str(int num)
{
    if (num == 0)
    {
        return;
    }
    num_to_str(num/10);
    putchar(num % 10 + '0'); //0的ascii码为48
    //printf("%d",num % 10);
}
int main(void)
{
    int num;
    scanf("%d",&num);
    num_to_str(num);

    system("pause");
    return 0;
}
