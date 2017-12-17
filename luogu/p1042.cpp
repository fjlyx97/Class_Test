#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int first_res[10240][2];
int second_res[10240][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char res;
    int first_Iwin = 0 , first_Ywin = 0;
    int second_Iwin = 0 , second_Ywin = 0;
    int i = 0 , j = 0;
    while (cin >> res)
    {
        if (res == 'W')
        {
            first_Iwin++;
            second_Iwin++;
        }
        else if(res == 'L')
        {
            first_Ywin++;
            second_Ywin++;
        }
        else if (res == 'E')
        {
            first_res[i][0] = first_Iwin;
            first_res[i][1] = first_Ywin;
            second_res[j][0] = second_Iwin;
            second_res[j][1] = second_Ywin;
            i++;
            j++;
            break;
        }
        if ((first_Iwin >= 11 || first_Ywin >= 11) && abs(first_Iwin-first_Ywin) >= 2)
        {
            first_res[i][0] = first_Iwin;
            first_res[i][1] = first_Ywin;
            i++;
            first_Iwin = 0;
            first_Ywin = 0;
        }
        if ((second_Iwin >= 21 || second_Ywin >= 21) && abs(second_Iwin-second_Ywin) >= 2)
        {
            second_res[j][0] = second_Iwin;
            second_res[j][1] = second_Ywin;
            j++;
            second_Iwin = 0;
            second_Ywin = 0;
        }
    }
    for (int k = 0 ; k < i ; k++)
    {
        cout << first_res[k][0] << ":" << first_res[k][1] << endl;
    }
    cout << endl;
    for (int k = 0 ; k < j ; k++)
    {
        cout << second_res[k][0] << ":" << second_res[k][1] << endl;
    }

    system("pause");
    return 0;
}