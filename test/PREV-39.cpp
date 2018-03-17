#include <iostream>
#include <cstdlib>
int index[13][32] = {0};
bool leap_year(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    return false;
}
inline bool judge_day(int mouth , int day , bool leap)
{
    switch (mouth)
    {
        case 1:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 2:
            if (leap == true)
            {
                if ( 1 <= day && day <= 29)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if ( 1 <= day && day <= 28)
                {
                    return true;
                }
                else
                {
                    return false;
                }

            }
            break;
        case 3:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 4:
            if ( 1 <= day && day <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 5:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 6:
            if ( 1 <= day && day <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 7:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 8:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 9:
            if ( 1 <= day && day <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 10:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 11:
            if ( 1 <= day && day <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 12:
            if ( 1 <= day && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
    }
}
void cal(int year , int month , int day)
{
    bool leap;
    if (year >= 60)
    {
        int temp_year = 1900+year;
        leap = leap_year(temp_year);
        if (1 <= month && month <= 12)
        {
            if (judge_day(month,day,leap) && index[month][day] == 0)
            {
                index[month][day] = 1;
                printf("%d-%02d-%02d\n",temp_year,month,day);
            }
        }
    }
    else
    {
        int temp_year = 2000+year;
        leap = leap_year(temp_year);
        if (1 <= month && month <= 12)
        {
            if (judge_day(month,day,leap) && index[month][day] == 0)
            {
                index[month][day] = 1;
                printf("%02d-%02d-%02d\n",temp_year,month,day);
            }
        }
    }
}
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char day[9];
    int num[3];
    char tmp[2];

    cin >> day;
    //init num
    tmp[0] = day[0];
    tmp[1] = day[1];
    num[0] = atoi(tmp);
    tmp[0] = day[3];
    tmp[1] = day[4];
    num[1] = atoi(tmp);
    tmp[0] = day[6];
    tmp[1] = day[7];
    num[2] = atoi(tmp);

    cal(num[0],num[1],num[2]);
    cal(num[2],num[0],num[1]);
    cal(num[2],num[1],num[0]);


    system("pause");
    return 0;
}