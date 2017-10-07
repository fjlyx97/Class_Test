#include <stdio.h>
#include <stdlib.h>
//指针数组
int main(void)
{ //char* ptr = "helloworld";
    //printf("%s %c", ptr , ptr[4]);
    int a = 1,
        b = 2,
        c = 3,
        d = 4,
        e = 5;
    int* arr[5] = {&a,&b,&c,&d,&e};
    printf("%d \t %p \t %p",*arr[0] , arr[0] , arr); //申明了一个指针数组，可以指向多个变量。

    int** arr1 = arr;


    system("pause");
    return 0;
}