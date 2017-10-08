#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int i , j = 0;
    for (i = 1 ; ; i++)
    {
        if ((i + 3) % 5 == 0 && (i - 3) % 6 == 0)
        {
            printf("%d\n",i);
            j++;
        }
        if (j == n)
        {
            break;
        }
    }

    system("pause");
    return 0;
}