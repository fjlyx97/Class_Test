#include <stdio.h>
#include <stdlib.h>
//extern 是用于跨文件定义，其他文件定义一个变量后，可以使用extern int 变量来申明全局变量。
//堆是自己操作，栈是机器自动释放
void fun()
{
    static int i;
    i++;
    printf("%d \n",i);
    printf("%d \n", b);
}
int main(void)
{
    printf("first:");
    fun();
    printf("second:");
    fun();

    system("pause");
    return 0;
}