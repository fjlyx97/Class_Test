#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a;
    scanf("%d\n",&a); //这里输入完一个数字后，需要再任意输入一个字符，否则无法结束程序，'\n'的原因。
    printf("%d",a);

    system("pause");
    return 0;
}