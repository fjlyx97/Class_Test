#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    char data[101];
    int top;
};
int main(void)
{
    /*回文字符串，即判断一个字符串是否对称*/

    struct stack s;     //初始化栈
    s.top = 0;

    char str[100];
    scanf("%s",str);

    int len = strlen(str);
    int mid = len / 2 - 1;//中间位置
    int i = 0;
    for (i = 0 ; i <= mid ; i++)
    {
        s.top++;
        s.data[s.top] = str[i];
    }
    int next;

    if (len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }

    for ( i = next ; i < len ; i++)
    {
        if (str[i] != s.data[s.top])
        {
            break;
        }
        s.top--;
    }
    if ( 0 == s.top)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    system("pause");
    return 0;
}