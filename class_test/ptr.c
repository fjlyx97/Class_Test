#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a = 10;
    int *p = &a;
    int* *p1 = &p; //这里代表生成一个二级指针，指针也是有地址的

    int *p2 = p; //这个代表的是地砖的传递，忽略了指针的地址的事实。


    system("pause");
    return 0;
}