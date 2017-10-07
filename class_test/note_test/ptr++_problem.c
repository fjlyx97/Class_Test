#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num[5] = {1,2,3,4,5};
    printf("%d",num++);
    int *p[5] = {&num[0],&num[1],&num[2],&num[3],&num[4]};
    int *p1 = num; //在这里c只是普通指针，并不称为数组指针或者指针数组。
    printf("%d",*p1++); //在这里是先执行p++，在执行*p.
                       //即*(p++)
    p1[3] == num[3]; //这是成立的，指针的下标运算 , p[2] == p+2;
    
    int b = 4;
    int *p2 = &b;
    p2[2] = 13; //按道理说已经越界，但编译器未报错
    //数组名和指针变量 数组名不允许自加的，且不参与运算，而指针变量可以
    //数组名是一个常量 , 而 2[p] 是合法的 ,等同于 *(2+p)
    


    system("pause");
    return 0;
}