#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void judgeNum(char* , int);
int main(void)
{
    int N;
    scanf("%d", &N);
    char *str[N];
    int i ;
    for ( i = 0 ; i < N ; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 32);
        scanf("%s",str[i]);
    }
    for ( i = 0 ; i < N ; i++)
    {
        judgeNum(str[i] , N);
    }

    system("pause");
    return 0;
}
void judgeNum(char* str , int N)
{    
    int j , k = 0 , l = 7 , temp_index = 0;
    int temp[4] = {0,0,0,0};
    for (j = 0 ; j < 32 ; j++)
    {
        if (str[j] == '0')
        {
            l--;
        }
        else if (str[j] == '1')
        {
            temp[temp_index] += 1 * pow(2,l);
            l--;
        }
        else if (str[j] == '2')
        {
            temp[temp_index] += 2 * pow(2,l);
            l--;
        }
        if ( (j + 1) % 8 == 0 )
        {
            temp_index++;
            l = 7;
        }
    }
    printf("%d.%d.%d.%d\n",temp[0],temp[1],temp[2],temp[3]);
}