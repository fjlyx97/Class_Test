#include <stdio.h>
#include <stdlib.h>
void judgeScore(int);
int main(void)
{
    int k;
    scanf("%d",&k);
    int * score = (int*)malloc(sizeof(int) * k);  //强行转换指针为int*
    int i = 0;
    for (i = 0; i < k ; i++)
    {
        scanf("%d",&score[i]);
    }
    for (i = 0 ; i < k ; i++)
    {
        judgeScore(score[i]);
    }
    free(score);


    system("pause");
    return 0;
}
void judgeScore(int num)
{
    if ( num <= 100 && 90 <= num)
    {
        printf("A\n");
    }
    else if ( num <=89 && 80 <= num)
    {
        printf("B\n");
    }
    else if ( num <=79 && 70 <= num)
    {
        printf("C\n");
    }
    else if ( num <=69 && 60 <= num)
    {
        printf("D\n");
    }
    else if ( num <=59 && 0 <= num)
    {
        printf("E\n");
    }
    else
    {
        printf("Score is error!\n");
    }
}