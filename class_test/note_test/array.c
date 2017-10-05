#include <stdio.h>
int main(void)
{
    int num;
    num = 0;

    //printf("%d",num);
    int array[3];
    printf("%d %d %d \n",array[0],array[1],array[2]); //-1231234 123123 123124
    int array1[3] = {3};
    printf("%d %d %d \n",array1[0],array1[1],array1[2]); // 3,0,0
    //如果数组不为其初始化任意一个数字，则编译器会默认初始化很奇怪的数字
    //但一旦初始化了一个数字，编译器则会讲剩余元素初始化为0.
    int array2 [2][3] = {1,2,3,4,5};
    //
    //int array3 [][4]; //error
    int array3 [][2] = {1,3,4,5}; //true

    return 0;
}
