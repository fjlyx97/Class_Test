#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    int i = 0;
    int mood;
    int result = 0;
    char occupation[1024];
    while (1)
    {
        scanf("%d",&N);
        getchar();
        if ( N == 0 )
        {
            break;
        }
        result = 0;
        mood = 80;
        gets(occupation);
        for ( i = 0 ; occupation[i] != '\0' ; i++)
        {
            if (occupation[i] == ' ')
            {
                continue;
            }
            else if (occupation[i] == 'S')
            {
                mood += 5;
            }
            else if (occupation[i] == 'Z')
            {
                mood += 1;
            }
            else if (occupation[i] == 'C')
            {
                mood -= 20;
            }
            result += 1;
            if (mood > 100)
            {
                mood = 100;
            }
            if (mood <= 0)
            {
                break;
            }
        }
        printf("%d\n",result);
    }

    system("pause");
    return 0;
}