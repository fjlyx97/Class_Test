#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int *num = (int*)malloc(sizeof(int) * (N+1));
    int i = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    int M , insertNum ;
    scanf("%d",&M);
    scanf("%d",&insertNum);
    for (i = N; i > M-1 ; i--)
    {
        num[i] = num[i-1];
    }
    num[M-1] = insertNum;
    for (i = 0 ; i < N+1 ; i++)
    {
        printf("%d ",num[i]);
    }
    free(num);
    system("pause");
    return 0;
}