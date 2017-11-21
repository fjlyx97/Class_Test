#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T , N , temp , ans = 0;
    scanf("%d",&T);
    while (T--)
    {
        ans = 0;
        scanf("%d",&N);
        while (N--)
        {
            scanf("%d",&temp);
            ans ^= temp;
        }
        printf("%d\n",ans);
    }

    system("pause");
    return 0;
}