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
        printf("��ǰΪ��%dҳ\n\n",i);
        printf("�������ֵΪ:%d,��СֵΪ:%d,ƽ��ֵΪ:%.2f\n\n",max,min,ave/100);
        printf("press any key to continue...");
        getche();
    }
    system("pause");
    return 0;
}