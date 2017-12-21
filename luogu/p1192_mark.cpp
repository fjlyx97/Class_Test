#include <iostream>
#include <algorithm>
using namespace std;
int ans = 0;
int book[100001] = {0};
void fun(int step , int N , int K)
{
    int i;
    if (step > N)
    {
        return;
    }
    if (step == N)
    {
        ans++;
        return;
    }
    for ( i = 1 ; i <= K ; i++)
    {
        fun(step+i,N,K);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , K;
    cin >> N >> K;
    fun(0,N,K);
    ans = ans % 100003;
    cout << ans << endl;

    system("pause");
    return 0;
}