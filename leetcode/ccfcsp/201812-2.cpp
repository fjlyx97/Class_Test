#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r , y , g;
    int n;
    int k , t;
    long long light_times; 
    long long current_time = 0;
    long long ans = 0;
    long long temp_time;

    cin >> r >> y >> g;
    cin >> n;
    light_times = r + y + g;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> k >> t;
        if (k == 0)
        {
            ans += t;
            current_time += t;
        }
        else
        {
            if (k == 1)
                temp_time = (current_time + r - t) % light_times;
            if (k == 2)
                temp_time = (current_time + y - t + r + g) % light_times;
            if (k == 3)
                temp_time = (current_time + g - t + r) % light_times;
            if (temp_time <= r)
            {
                ans += r - temp_time;
                current_time += r-temp_time;
            }
            else if (temp_time >= g+r)
            {
                ans += r + (r+y+g) - temp_time;
                current_time += r + (r+y+g) - temp_time;
            }
        }
    }
    cout << ans << endl;


    system("pause");
    return 0;
}