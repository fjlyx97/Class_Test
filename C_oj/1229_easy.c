#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a , b , c;
    int ans = 1;
    int i;
    scanf("%d %d %d",&a,&b,&c);
    for ( i = 0 ; i < b ; i++)
    {
        ans = (ans * a) % c; 
    }
    printf("%d",ans);

    system("pause");
    return 0;
}