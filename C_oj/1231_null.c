#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i = 1 , j = 1 , k = 1;
    int num = 0;
    int save_num[1000] = {1};
    int l = 0 , temp = 0;
    for (i = 1 ; i < 10 ; i++)
    {
        for (j = i ; j < 10 ; j++)
        {
            for (k = j ; k < 10 ; k++)
            {
                if ( (i + j + k) % 2 == 1 )
                {
                    for (l = 0 ; ;l++)
                    {
                        if ( save_num[l] == 0)
                        {
                            printf("%d\n",i+j+k);
                            save_num[l] = (i + j + k);
                            num++;
                            break;
                        }
                        if ( (i + j + k ) == save_num[l])
                        {
                            break;
                        }
                    } 
                }
            }
        }
    }
    printf("%d",num);
    system("pause");
    return 0;
}