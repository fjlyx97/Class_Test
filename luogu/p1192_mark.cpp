#include <iostream>
#include <algorithm>
using namespace std;
long long book[100001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , K;
    cin >> N >> K;
    for (int i = 1 ; i <= K ; i++)
    {
        book[i] = 1;
    }
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = i-K ; j < i ; j++)
        {
            if (j < 1)
            {
                continue;
            }
            book[i] += book[j];
        }
        book[i] %= 100003;
    }
    cout << book[N] << endl;
    system("pause");
    return 0;
}