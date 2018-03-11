#include <iostream>
using namespace std;
int num[101][101] = {0};
int index[101] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans = 1;
    int m;
    int a , b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        num[a][index[a]] = b;
        num[b][index[b]] = a;
        index[a]++;
        index[b]++;
    }
    
    system("pause");
    return 0;
}