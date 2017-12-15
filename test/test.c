#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x;
    float y;
    scanf("%d",&x);
    if(x<=150)
        printf("%.2f",0);
    else if(x<=10000)
        printf("%.2f",y=(x-150)*1.0/3);
    else 
        printf("%.2f",y=(x-10000)*(3.0/5)+(10000-150)*(1.0/3));
    system("pause");
    return 0;
}