#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S , M;
    int status = 0;
    cin >> S >> M;
    while(S > 0)
    {
        S -= M;
        if (S <= 0)
            break;
        status = !status;
    }
    if (status)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



    system("pause");
    return 0;
}