#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    float height = 100.0;
    float length = 0;
    scanf("%d",&N);
    int i;
    for (i = 1 ; i <= N ; i++)
    {
        if (i == 1)
        {
            length = 100;
        }
        else if (i > 1)
        {
            length += height * 2;
        }
        height = height / 2;
    }
    printf("%.2f %.2f", length , height);
    system("pause");
    return 0;
}