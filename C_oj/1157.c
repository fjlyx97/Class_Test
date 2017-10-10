#include <stdio.h>
#include <stdlib.h>
int main()
{
    float x;
    scanf("%f",&x);
    float result = x ;
    int i = 0;
    for ( i = 1 ; ; i++)
    {
        if (i % 2 == 0)
        {
            result += x / (i+1); 
        }
        else if (i % 2 == 1) 
        {
            result -= x / (i+1);
        }
        if ( (x / (i+1)) < 0.00001 )
        {
            break;
        }
    }
    printf("%.2f",result);
    system("pause");
}