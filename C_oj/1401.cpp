#include <stdio.h>
int main(void)
{
    int N;
    int id[99] , attack[99] , defence[99];
    char sex[99];
    int save_id[99];
    scanf("%d",&N);
    int i , k = 0 , j = 0;
    for ( i = 0 ; i < N ; i++)
    {
        scanf("%d,%d,%d,%c",&id[i],&attack[i],&defence[i],&sex[i]);
    }
    for ( i = 0 ; i < N ; i++)
    {
        if (sex[i] == 'M')
        {
            save_id[k] = i+1;
            k++;
        }
    }  
    int max_attack = 0;
    int index = 0;
    for ( i = 0 ; i < k ; i++)
    {
        if (attack[save_id[i]-1] > max_attack)
        {
            max_attack = attack[save_id[i]-1];
            index = save_id[i]-1;
        }
    }
    int save_attack_id[99];
    for ( i = 0 ; i < k ; i++)
    {
        if (attack[save_id[i]-1] == max_attack)
        {
            save_attack_id[j] = save_id[i]-1;
            j++;
        }
    }
    int max_defence = 0;
    for ( i = 0 ; i < j ; i++)
    {
        if (defence[save_attack_id[i]] > max_defence)
        {
            max_defence = defence[save_attack_id[i]];
            index = save_attack_id[i];
        }
    }
    printf("%d",id[index]);
    return 0;
}