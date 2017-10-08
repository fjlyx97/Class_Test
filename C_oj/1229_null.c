#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    long int a , b, c;
    long int result;
    scanf("%d %d %d",&a ,&b ,&c);
    result = pow(a,b);
    result = result % c;
    printf("%d",result);



    system("pause");
    return 0;
}