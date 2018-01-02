#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int i , j , k;
    int max;
    int min;
    int num;
    float ave;
    for ( i = 1 ; i <= 10 ; i++)
    {
        min = 9999;
        max = -1;
        ave = 0;
        system("cls");
        for ( j = 1 ; j <= 10 ; j++)
        {
            for ( k = 1 ; k <= 10 ; k++)
            {
                num = rand()%1000;
                max = num > max ? num : max;
                min = num < min ? num : min;
                ave += num;
                printf("%3d ",num);
            }
            printf("\n");
        }
        printf("\n\n\n\n");
        printf("当前为第%d页\n\n",i);
        printf("其中最大值为:%d,最小值为:%d,平均值为:%.2f\n\n",max,min,ave/100);
        printf("press any key to continue...");
        getche();
    }
    system("pause");
    return 0;
}