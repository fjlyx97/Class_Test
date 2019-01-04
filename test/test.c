#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N;
    int j = 0;
    int o = 0;
    int a;
    scanf("%d",&N);
    N = abs(N);
    while(N)
    {
        a = N%10;
        a = a%2;
        N /= 10;
        if (a == 1)
            j++;
        if (a == 0)
            o++;
    }
    printf("%d,%d\n",j,o);
    system("pause");
    return 0;
}
