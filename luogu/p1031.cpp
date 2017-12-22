#include <iostream>
using namespace std;
int num[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for ( int i = 1 ; i <= N ; i++)
    {
        cin >> num[i];
    }

    system("pause");
    return 0;
}