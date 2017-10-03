#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mul(int);
void test( int*, int*);
int main(void)
{
    int* a = (int*)malloc(sizeof(int));
    *a = 1;
    int* b = (int*)malloc(sizeof(int));
    *b = 2;
    printf("%d %d",a,b);
    test(a,b);
    printf("%d %d",a,b);
    system("pause");
    return 0;
}
void test(int* a,int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int mul(int num)
{
    int i;
    int result;
    for (i = 1; i < num ; i++)
    {
        result += result * i;
    }
    return result;
}