/**
 * Description

Tom拥有许多色彩缤纷的卡片，一共有4种颜色，分别为：红，绿，蓝，黄。 
Tom随机取出N张卡片排成一列，他突然觉得不够美观。他决定替换掉某些卡片使得相邻两张卡片的颜色各不相同。 
你的任务就是帮他计算出至少需要替换掉的卡片数量。由于每种颜色的卡片他都有很多，所以可以认为每种颜色的卡片数量是无限的。

Input

输入数据的第一行为一个整数N，表示序列中有N个字符(1 <= N <= 10000)。接着一行有N个字符A1,…,An，Ai为‘R’, ‘G’, ‘B’, ‘Y’中的一个字符，表示第i张卡片的颜色，R表示红色，G表示绿色，B表示蓝色，Y表示黄色。

Output

输出一个整数C，表示至少需要替换掉的卡片数。

Sample Input


10
RGGBBBRYYB
Sample Output


3
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char* str = (char*)malloc(sizeof(char) * N); //动态申请字符数组空间。
    scanf("%s",str);
    int i , index = 1 , result = 0;
    for (i = 0 ; i < N ; i++)
    {
        if (str[i] == str[i+1])
        {
            index += 1; //如果相等，索引加一
        }
        else
        {
            if (index % 2 == 1)
            {
                result += index / 2;
            }
            else if (index % 2 == 0)
            {
                result += index / 2;
            }
            index = 1;
        }
    }
    printf("%d",result);
    //free(str);
    system("pause");
    return 0;
}