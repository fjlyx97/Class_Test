#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int year = 0;
    float x;
    float y = 10.0;
    scanf("%f",&x);
    float y_2 = 20.0;
    while (y_2 >= y)
    {
        y = (1 + x) *y;
        year++;
    }
    printf("%d",year);



    system("pause");
    return 0;
}