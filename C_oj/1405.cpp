#include <stdio.h>
#include <string.h>
int main(void)
{
    char answer[51];
    char my_answer[51];
    gets(answer);
    gets(my_answer);
    int len = strlen(answer);
    int score = 0;
    int i;
    int flag = 1;
    char temp;
    for ( i = 0 ; i < len ; i++)
    {
        if (my_answer[i] != ' ')
        {
            temp = my_answer[i];
            break;
        }
    }
    for ( i = 0 ; i < len ; i++)
    {
        if (my_answer[i] == ' ')
        {
            continue;
        }
        if (my_answer[i] != temp)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        score = 0;
        printf("%d",score);
        return 0;
    }
    int right = 0 , wrong = 0;
    for ( i = 0 ; i < len ; i++)
    {
        if ( answer[i] == my_answer[i])
        {
            right += 1;
        }
        else if (my_answer[i] == ' ')
        {
            continue;
        }
        else
        {
            wrong += 1;
        }
    }
    score = right * 2 - wrong * 2;
    if (score <= 0) score = 0;
    printf("%d",score);
    return 0;
}