#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int year , mouth , day;
    int days = 0;
    int flag = 0;
    scanf("%4d-%2d-%2d",&year,&mouth,&day);
    for ( int i = 1990 ; i < year ; i++)
    {
        if ( (i % 400 == 0 && i % 4 == 0) || (i % 4 == 0 && i % 100 != 0))
        {
            days += 366;
        }
        else
        {
            days += 365;
        }
    }
    if (( year % 400 == 0 && year % 4 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        flag = 1;
    }
    for (int j = 1 ; j < mouth ; j++)
    {
        if (j == 1)
            days += 31;
        if (j == 2 && flag == 0)
            days += 28;
        else
            days += 29;
        if (j == 3)
            days += 31;
        if (j == 4)
            days += 30;
        if (j == 5)
            days += 31;
        if (j == 6)
            days += 30;
        if (j == 7)
            days += 31;
        if (j == 8)
            days += 31;
        if (j == 9)
            days += 30;
        if (j == 10)
            days += 31;
        if (j == 11)
            days += 30;
    }
    days += day;
    if (days % 5 == 4 || days % 5 == 0)
    {
        printf("He is having a rest");
    }
    else
    {
        printf("He is working");
    }
    system("pause");
    return 0;
}