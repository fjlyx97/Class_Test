#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    int ans = 0;
    int temp;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&temp);
        ans ^= temp;
    }

    printf("%d",ans);
    system("pause");
    return 0;
}