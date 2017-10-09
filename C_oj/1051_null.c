#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    //int* num = (int*)malloc(sizeof(int) * N);
    int num[N];
    int j;
    for ( j = 0 ; j < N ; j++)
    {
        num[j] = 1;
    }
    int i = 0 , index = 0 , pep_sum = N;
    int add_ary = 0;
    while (pep_sum != 1)
    {
        //add_ary += num[i];
        index += 1;
        if (index % 4 == 0)
        {
            num[i] = 0;
            pep_sum -= 1;
        }
        if ( (i-1) == N)
        {
            i = -1;
            //add_ary = 0;
        }
        i++;
    }
    int z;
    if (pep_sum == 1)
    {
        for (z = 0; z < N ; z++)
        {
            if (num[z] == 1)
            {
                printf("%d\n",z+1);
            }
        }
    }
    
    system("pause");
    return 0;
}