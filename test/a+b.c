#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a = 12;
    int *p = &a;
    printf("%p %p %d",p ,&p ,*p);
    system("pause");
    return 0;
}