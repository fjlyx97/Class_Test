#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float f;
    scanf("%f",&f);
    float c;
    c = 5.0/9 * (f-32);
    printf("%.2f",c);

    system("pause");
    return 0;
}