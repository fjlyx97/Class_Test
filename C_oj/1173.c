#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char a;
    scanf("%c",&a);
    if( a <= 90 && a >= 65)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    system("pause");
    return 0;
}