#include <iostream>
using namespace std;
int num[1000001];
int getf(int v)
{
    if (num[v] == v)
    {
        return num[v];
    }
    else
    {
        num[v] = getf(num[v]);
        return num[v];
    }
}
void merge(int a, int b)
{
    int t1 , t2;
    t1 = getf(a);
    t2 = getf(b);
    if (t1 != t2)
    {
        num[t2] = t1;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m , n;
    int k;
    int a , b;
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m*n ; i++)
    {
        num[i] = i;
    }
    while (k--)
    {
        cin >> a >> b;
        merge(a,b);
    }
    int ans = 0;
    for (int i = 1 ; i <= n*m ; i++)
    {
        if (num[i] == i)
        {
            ans++;
        }
    }
    cout << ans << endl;


    system("pause");
    return 0;
}