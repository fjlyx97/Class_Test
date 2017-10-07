#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
int main(void)
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {a[4]}; //可以使用这种赋值方法，将a中的元素赋值给b
    //有两种常见赋值，一种是循环，一种是memcpy复制
    int i = 0;
    //循环赋值
    for (i = 0 ; i < 5; i++)
    {
        b[i] = a[i];
    }
    //memcpy赋值,包含在<memory.h>或<string.h>中 memcpy(要被赋值，要赋值，赋值大小);
    //内存拷贝，认地址不认元素
    memcpy(b,a,sizeof(int)*5);
    memcpy(&b[0],&a[0],sizeof(int)*5);



    system("pause");
    return 0;
}