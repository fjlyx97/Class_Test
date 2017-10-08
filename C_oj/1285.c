#include <stdio.h>
#include <stdlib.h>
void judgeNum(int);
int main(void)
{
    int N;
    scanf("%d",&N);
    int *num = (int*)malloc(sizeof(int) * N);
    int i = 0;
    for(; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    for (i = 0; i < N ; i++)
    {
        judgeNum(num[i]);
    }
    free(num);

    system("pause");
    return 0;
}
void judgeNum(int num)
{
    if (90 <= num && num <= 100)
    {
        printf("excellent\n");
    }
    else if (80 <= num && num <= 89)
    {
        printf("good\n");
    }
    else if (70 <= num && num <= 79)
    {
        printf("soso\n");
    }
    else if (60 <= num && num <= 69)
    {
        printf("pass\n");
    }
    else if (0 <= num && num <= 59)
    {
        printf("fail\n");
    }
    else
    {
        printf("wrong");
    }
}