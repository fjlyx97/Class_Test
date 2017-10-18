#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    int i = 0;
    int j = 0;
    scanf("%d",&N);
    int insert_num[11] = {0};
    int result = 0;
    int num;

    for (j = 0 ; j < N ; j++)
    {
        scanf("%d",&num);
        for (i = 0 ; i < num ;i++)
        {
            scanf("%d",&insert_num[i]);
            result += insert_num[i];
        }
        result -= num-1;
        printf("%d\n",result);
        result = 0;
    }

    system("pause");
    return 0;
}