#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int num[N];
    for ( int i = 0 ; i < N ; i++)
    {
        cin >> num[i];
    }
    sort(num,num+N);
    for (int i = N-1 ; i >= 0 ; i--)
    {
        if (num[i] > num[i-1])
        {
            swap(num[i],num[i-1]);
            break;
        }
    }
    for (int i = 0 ; i < N ; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}