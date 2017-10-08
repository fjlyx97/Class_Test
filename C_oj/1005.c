#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int character = 0, blank = 0, digit = 0 , other = 0;
    char str[1024];
    gets(str);
    int i;
    for ( i = 0 ; ; i++)
    {
        if (str[i] == 59)
        {
            break;
        }
        if (str[i] == 32)
        {
            blank += 1;
        }
        else if (48 <= str[i] && str[i] <= 57)
        {
            digit += 1;
        }
        else if (97 <= str[i] && str[i] <= 122)
        {
            character += 1;
        }
        else if (65 <= str[i] && str[i] <= 90)
        {
            character += 1;
        }
        else
        {
            other += 1;
        }
    }
    printf("character=%d,blank=%d,digit=%d,other=%d",character,blank,digit,other);
    system("pause");
    return 0;
}