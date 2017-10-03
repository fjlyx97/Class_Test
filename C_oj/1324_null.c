#include <stdio.h>
#include <stdlib.h>
void fun(char* , int);
int main(void)
{
    char string[51];
    gets(string);
    char* test = string;
    int i , max_index = 0 , over_index;
    for (i = 0; i < 51 ; i++)
    {
        if (string[i] == '\0')
        {
            break;
        }
        if (string[i+1] > string[i])
        {
            max_index = i+1;
        }
    }

    system("pause");
    return 0;
}
void fun(char* string ,int index)
{

}