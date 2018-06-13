#include <iostream>
#include <cstring>
inline int max(int a , int b)
{
    if (a > b) return a;
    else return b;
}
inline int min(int a , int b)
{
    if (a < b) return a;
    else return b;
}
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int num[101] = {0};
    int updp[101] = {0};
    int lowdp[101] = {0};
    int ans1 = 0 , ans2 = 0;
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> num[i];
    }
    for (int i = 1 ; i <= N ; i++)
    {
        updp[i] = lowdp[i] = 1;
    }
    for (int i = 2 ; i <= N ; i++)
    {
        for (int j = 1 ; j < i ; j++)
        {
            if (num[i] >= num[j])
            {
                updp[i] = max(updp[i],updp[j]+1);
            }
            if (num[i] <= num[j])
            {
                lowdp[i] = max(lowdp[i],lowdp[j]+1);
            }
        }
        if (updp[i] > ans1) ans1 = updp[i];
        if (lowdp[i] > ans2) ans2 = lowdp[i];
    }
    ans1 = N-ans1;
    ans2 = N-ans2;
    if (ans1 == N || ans2 == N)
    {
        cout << 0 << endl;
        return 0;
    }
    if (ans1 <= ans2 ) 
    {
        cout << ans1 << endl;
    }
    else if (ans2 < ans1)
    {
        cout << ans2 << endl;
    }
    system("pause");
    return 0;
}