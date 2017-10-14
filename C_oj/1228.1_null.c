#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f[6];
int main(void)
{
    int i , j ;
    memset(f,0,sizeof(f));
    f[1] = 1;
    f[2] = 2;
    for (i = 3 ; i <= 6 ;i++)
    {
        for ( j = 1 ; j < i ; j++)
        {
            f[i] += f[j];
        }
        f[i]++;
    }
    printf("%d\n",f[6]);
    system("pause");
    return 0;
}