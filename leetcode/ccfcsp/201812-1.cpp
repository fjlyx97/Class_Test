#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,y,g;
    int n;
    cin >> r >> y >> g;
    cin >> n;
    int k , t;
    int ans_time = 0;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> k >> t;
        if (k == 0)
        {
            ans_time += t;
        }
        if (k == 1)
        {
            ans_time += t;
        }
        if (k == 2)
        {
            ans_time += t+r;
        }
        if (k == 3)
        {
            continue;
        }
    }
    cout << ans_time << endl;



    system("pause");
    return 0;
}