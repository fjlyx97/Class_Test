#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cal_primer(int* primer)
{
    int i , j , k = 0;
    int status = 0;
    for ( i = 2 ; i <= 823 ; i++)
    {
        status = 0;
        for ( j = 2 ; j < i ; j++)
        {
            if ( i % j == 0)
            {
                status = 1;
                break;
            }
        }
        if (status == 0)
        {
            primer[k] = i;
            k++;
        }
    }
}
int main(void)
{
    int primer[143];
    cal_primer(primer);
    int people_num;
    scanf("%d",&people_num);
    int i = 0 , j = 0 , k = 0;
    char name[people_num][31];
    int game_id[4] = {0};
    int order[4] = {0};
    int scores[people_num] = {0};
    int temp;
    char c;
    int number = 0;
    for (i = 0 ; i < people_num ; i++)
    {
        scanf("%s",&name[i][0]);
    }
    for ( i = 0 ; i < 4 ; i++)
    {
        scanf("%d",&game_id[i]);
        if ( (c = getchar()) == '\n')
        {
            break;
        }
    }
    for ( j = 0 ; j <= i ; j++)
    {
        scanf("%d",&order[j]);
    }
    int result = 0;
    for ( j = 0 ; j <= i ; j++)
    {
        result = 0;
        number = 0;
        if (order[j] == 1)
        {
            for ( k = 0 ; k < 143 ; k++)
            {
                result += primer[k];
                temp = result;
                while(temp)
                {
                    if (temp % 10 == 0)
                    {
                        number += 1;
                    }
                    temp /= 10;
                }
                if (number % 2 == 1)
                {
                    scores[k%people_num] += 1;
                    break;
                }
            }
        }
        else if (order[j] == 2)
        {
            for ( k = 0 ; k < 143 ; k++)
            {
                result += primer[k];
                temp = primer[k] - (result-primer[k]);
                while(temp)
                {
                    if (temp % 10 == 0)
                    {
                        number += 1;
                    }
                    temp /= 10;
                }
                if (number % 2 == 1)
                {
                    scores[k%people_num] += 1;
                    break;
                }
            }
        }
        else if (order[j] == 3)
        {
            for ( k = 0 ; k < 143 ; k++)
            {
                result += primer[k];
                temp = primer[k] * (result-primer[k]);
                while(temp)
                {
                    if (temp % 10 == 0)
                    {
                        number += 1;
                    }
                    temp /= 10;
                }
                if (number % 2 == 1)
                {
                    scores[k%people_num] += 1;
                    break;
                }
            }
        }
        else if (order[j] == 4)
        {  
            for ( k = 0 ; k < 143 ; k++)
            {
                result += primer[k];
                temp = primer[k] / (result-primer[k]);
                while(temp)
                {
                    if (temp % 10 == 0)
                    {
                        number += 1;
                    }
                    temp /= 10;
                }
                if (number % 2 == 1)
                {
                    scores[k%people_num] += 1;
                    break;
                }
            }
        }
    }
    char name_temp[31];
    for ( i = 0 ; i < people_num-1 ; i++)
    {
        for (j = 0 ; j < people_num - i - 1 ; j++)
        {
            if (scores[j] < scores[j+1])
            {
                temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
                strcpy(name_temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],name_temp);
            }
        }
    }
    for ( i = 0 ; i < people_num ; i++)
    {
        printf("%d %s\n",i+1,name[i]);
    }

    system("pause");
    return 0;
}