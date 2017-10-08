#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[51]; //a 97 z 122 Z 90 A 65
    scanf("%s",str);
    int i;
    for (i = 0 ; i < 51 ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }
    printf("%s",str);
    system("pause");
    return 0;
}