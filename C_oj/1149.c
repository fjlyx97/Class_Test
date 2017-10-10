#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char a;
    scanf("%c",&a);
    if ( a >= 93 && a <= 122)
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