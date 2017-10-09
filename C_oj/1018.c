#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char* str = (char*)malloc(sizeof(char) * N);
    scanf("%s",str);
    int i , index = 1 , result = 0;
    for (i = 0 ; i < N ; i++)
    {
        if (str[i] == str[i+1])
        {
            index += 1;
        }
        else
        {
            if (index % 2 == 1)
            {
                result += index / 2;
            }
            else if (index % 2 == 0)
            {
                result += index / 2;
            }
            index = 1;
        }
    }
    printf("%d",result);
    system("pause");
    return 0;
}