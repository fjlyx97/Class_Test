#include <iostream>
using namespace std;
int book[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    int l , r;
    while (n--)
    {
        cin >> l >> r;
        if ( l > m || r > m || l < 1 || r < 1)
        {
            cout << "Crossing the line" << endl;
            continue;
        }
    }

    system("pause");
    return 0;
}