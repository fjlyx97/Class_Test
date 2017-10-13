#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[n];
    //int *num = (int*)malloc(sizeof(int) * n);
    int i = 0;
    for (i = 0 ; i < n ; i++)
    {
        num[i] = 1;
    }
    int off_lamp = 0;
    int j;
    int k;
    int result = 0;
    for ( i = 1 ; i < n-1 ; i++)
    {
        num[i] = 0;
        off_lamp++;
        for (j = i+2 ; j < n-1 ; j++)
        {
            num[j] = 0;
            off_lamp++;
            for ( k = j+2 ; k < n-1 ; k++)
            {
                num[k] = 0;
                off_lamp++;
                if (off_lamp == 3)
                {
                    off_lamp = 2;
                    num[k] = 1;
                    result += 1;
                }
            }
            num[j] = 1;
            off_lamp = 1;
        }
        num[i] = 1;
        off_lamp = 0;
    }
    printf("%d",result);
    system("pause");
    return 0;
}