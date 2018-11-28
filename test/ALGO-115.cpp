#include <iostream>
using namespace std;
int n;
int num[23];
int book[23] = {0};
int T;
int ans = 0;
void dfs(int step , int totalNum)
{
    if (totalNum == T && step != 0)
    {
        for (int i = 0 ; i < n ; i++)
        {
            if (book[i] == 1)
            {
                cout << num[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    if (step > n)
    {
        return;
    }
    for (int i = n-1 ; i >= 0 ; i--)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            dfs(step+1,totalNum+num[i]);
            book[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> num[i];
    }
    cin >> T;
    dfs(0,0);

    system("pause");
    return 0;
}