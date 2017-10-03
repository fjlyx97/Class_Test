#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    float num[N];
    int i;
    float result = 0;
    for(i = 0 ; i < N; i++)
    {
        scanf("%f",&num[i]);
        result += num[i];
    }
    result = result / N;
    printf("%.2f",result);
    
    system("pause");
    return 0;
}