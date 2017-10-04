#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num[5] = {1,2,3,4,5};
    int *p = num; //在这里c只是普通指针，并不称为数组指针或者指针数组。
    printf("%d",*p++); //在这里是先执行p++，在执行*p.
                       //即*(p++)
    p[3] == num[3]; //这是成立的，指针的下标运算 , p[2] == p+2;
    
    int b = 4;
    int *p1 = &b;
    p1[2] = 13; //按道理说已经越界，但编译器未报错
    


    system("pause");
    return 0;
}