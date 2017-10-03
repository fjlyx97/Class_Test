#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(void)
{
    char a , b;
    /*
    scanf("%c", &a);
    scanf("%c", &b); //scanf可以读入回车
    printf("%c %c" , a , b);
    */

    /*
    scanf("%c", &a);
    fflush(stdin); //fflush可以清空缓存区
    scanf("%c", &b);
    printf("%c %c" , a , b);
    */

    int i;
    for (i=0 ; i<100; i++)
    {
        printf("%d",i);
        fflush(stdout);
        Sleep(1);
    }

    system("pause");
    return 0;
}