#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int year = 1900;
    int mouth = 1;
    int pin_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int run_days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int week_day = 1;
    int res[8] = {0};
    
    cin >> n;
    for ( int i = year ; i < year+n ; i++)
    {
        if ( (i % 4 == 0 && i % 100 != 0) || ( i % 400 == 0) )  //闰年
        {
            for (int j = 1 ; j <= 12 ; j++)
            {
                for (int k = 1 ; k <= run_days[j] ; k++)
                {
                    if ( k == 13)
                    {
                        res[week_day]++;
                    }
                    week_day++;
                    if (week_day > 7 )
                    {
                        week_day %= 7;
                    }
                }
            }
        }
        else 
        {
            for (int j = 1 ; j <= 12 ; j++)
            {
                for (int k = 1 ; k <= pin_days[j] ; k++)
                {
                    if ( k == 13)
                    {
                        res[week_day]++;
                    }
                    week_day++;
                    if (week_day > 7 )
                    {
                        week_day %= 7;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d %d %d %d",res[6],res[7],res[1],res[2],res[3],res[4],res[5]);
    system("pause");
    return 0;
}