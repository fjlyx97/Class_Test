#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int add_num(int);
int main(void)
{
    float x;
    scanf("%f",&x);
    float result = x;
    int i;
    float temp;
    for (i = 1 ; ; i++)
    {
        if (i % 2 == 0)
        {
            result += pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        }
        else if ( i % 2 == 1)
        {
            result -= pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        }
        temp = pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        //if (temp < 0)
        //{
        //    temp = -temp;
        //}
        printf("%f\n",temp);
        if (temp < pow(10.0,-5))
        {
            break;
        }
    }
    printf("%.3f",result);

    system("pause");
    return 0;
}
int add_num(int num)
{
    int i;
    int result = 1;
    for (i = num ;i > 0 ; i--)
    {
        result = result * i; 
    }
    return result;
}