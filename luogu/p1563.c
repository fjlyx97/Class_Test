#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    /* 0 内 1 外 */
    int n , m;
    scanf("%d %d",&n,&m);
    int director[n];
    char name[n][11];
    int i = 0;
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d",&director[i]);
        scanf("%s",&name[i][0]);
    }
    int cmd[m][2];
    for ( i = 0 ; i < m ; i++)
    {
        scanf("%d %d",&cmd[i][0],&cmd[i][1]);
    }
    int index = 0;
    /* 0 左 1 右 */
    int temp;
    for ( i = 0 ; i < m ; i++)
    {
        if ( 0 == director[index] )
        {
            if (cmd[i][0] == 0)
            {
                temp = index - cmd[i][1];
                if ( temp < 0 )
                {
                    index = (n + temp ) % n;
                }
                else
                {
                    index = temp;
                }
            }
            else
            {
                temp = index + cmd[i][1];
                if ( temp > n-1)
                {
                    index = temp - n;
                }
                else
                {
                    index = temp;
                }
            }
        }       
        else
        /* 0 左 1 右 */
        {
            if (cmd[i][0] == 1)
            {
                temp = index - cmd[i][1];
                if ( temp < 0 )
                {
                    index = (n + temp ) % n;
                }
                else
                {
                    index = temp;
                }
            }
            else
            {
                temp = index + cmd[i][1];
                if ( temp > n-1)
                {
                    index = temp - n;
                }
                else
                {
                    index = temp;
                }
            }
        }    
    }
    printf("%s",name[index]);
    system("pause");
    return 0;
}