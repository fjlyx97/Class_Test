#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int num;
    int result = 0;
    scanf("%d",&num);
    int round = 0;
    int temp = num;
    while (temp >= 10)
    {
        temp = temp / 10.0;
        round += 1;
    }
    round += 1;
    int i , temp_1;
    for (i = round ; i > 0 ; i--)
    {
        temp_1 = floor(num / pow(10.0,i-1));
        num = num - temp_1 * pow(10.0,i-1); 
        result += temp_1;
    }
    printf("n=%d;sum=%d",round,result);

    system("pause");
    return 0;
}