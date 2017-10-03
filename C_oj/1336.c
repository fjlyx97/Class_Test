#include <stdio.h>
int main(void)
{
    char string[100];
    gets(string);
    int i;
    for (i = 0 ; i < 100 ; i++)
    {
        if (string[i] == '-')
        {
            if (string[i-1] <= 52 && string[i+1] >= 52)
            {
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
}