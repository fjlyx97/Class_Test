#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    char str[101];
    int i = 0;
    int result = 0;
    while (T--)
    {
        scanf("%s",str);
        result = 0;
        for ( i = 0; str[i] != '\0' ; i++)
        {
            if (str[i] == 'C')
            {
                result += 12;
            }
            else if (str[i] == 'H')
            {
                result += 1;
            }
            else
            {
                result += 16;
            }
        }
        printf("%d\n",result);

    }

    system("pause");
    return 0;
}