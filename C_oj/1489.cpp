#include <iostream>
using namespace std;
#define min(a,b) a<b?a:b
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int num[11];
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> num[i];
    }
    int ans = 0;
    bool book[2] = {false , false};
    int days[2] = {0};
    int status[2] = {-1,-1};
    for (int i = 0 ; i < N ; i++)
    {
        if (book[0] == false)
        {
            book[0] = true;
            status[0] = num[i];
            if (num[i] == 1 && status[1] == 0)
            {
                days[0] = 10;
                days[1] += 10;
            }
            else
            {
                days[0] = 10;
            }
        }
        else if (book[1] == false)
        {
            book[1] = true;
            status[1] = num[i];
            if (num[i] == 1 && status[0] == 0)
            {
                days[0] += 10;
                days[1] = 10;
            }
            else
            {
                days[1] = 10;
            }
        }
        if (book[0] == true && book[1] == true)
        {
            int temp_index;
            if (days[0] < days[1])
            {
                temp_index = 0;
                book[0] = false;
                ans+= days[0];
                days[1] -= days[0];
                days[0] = 0;
            }
            else if (days[0] > days[1])
            {
                temp_index = 1;
                book[1] = false;
                ans += days[1];
                days[0] -= days[1];
                days[1] = 0;
            }
            else
            {
                book[1] = false;
                book[0] = false;
                ans += days[0];
                days[0] = 0;
                days[1] = 0;
            }
        }
        else
        {
            if (book[0] == true)
            {
                days[0]--;
            }
            if (book[1] == true)
            {
                days[1]--;
            }
        }
    }
    cout << ans << endl;

    system("pause");
    return 0;
}