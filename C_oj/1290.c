#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[51]; //a 97 z 122 Z 90 A 65
    gets(str);
    //fgets(str,51,stdin);
    int i;
    for (i = 0 ; i < 51 ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
    }
    printf("%s",str);
    system("pause");
    return 0;
}
