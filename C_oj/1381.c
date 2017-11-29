#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int fz1 , fm1 , fz2 , fm2;
    scanf("%d %d %d %d",&fz1,&fm1,&fz2,&fm2);
    int down_num = fm1 * fm2;
    int up_num = fz1 * (down_num / fm1 ) + fz2 * (down_num / fm2);
    int i = 0;
    int status;
    while (1)
    {
        status = 0;
        for ( i = 2 ; i <= up_num ; i++)
        {
            if (up_num % i == 0)
            {
                if (down_num % i == 0)
                {
                    up_num /= i;
                    down_num /= i;
                    status = 1;
                    break;
                }
            }
        }
        if ( status == 0 )
        {
            break;
        }
    }
    printf("%d/%d",up_num,down_num);
    system("pause");
    return 0;
}