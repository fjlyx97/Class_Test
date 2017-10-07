#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num[5] = {1,2,3,4,5};
    //要生成一个指针指向数组，通过分解可以得到
    //*p1 代表指针
    //int[5]代表数组
    //实际理解是int[5] *p1; 但是编译器不允许通过
    //根据优先级int *p1[5]，会先和中括号结合，所以需要括号将p1括起来
    int (*p1)[5] = &num; //用五个元素的数组指针去装五个元素的地址
    //元素个数一定要一样，否则就是不同类型



    system("pause");
    return 0;
}