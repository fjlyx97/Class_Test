#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int hour = c-1-a;
    int minute = (60-b)+d;
    if (minute > 60)
    {
        minute %= 60;
        hour += 1;
    }
    cout << hour << " " << minute << endl;
    system("pause");
    return 0;
}