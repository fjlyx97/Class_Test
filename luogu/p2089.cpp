#include <iostream>
#include <cstring>
using namespace std;
int batching[11];
int book_batching[10001][11];
int k = 1;
int book[11] = {0};
int n;
int ans = 0;
void dfs(int step)
{
    if (step == 11)
    {
        int temp = 0;
        for ( int i = 1 ; i < 11 ; i++)
        {
            temp += batching[i];
        }
        if (temp == n)
        {
            memcpy(book_batching[k],batching,sizeof(batching));
            k++;
            ans++;
        }
        return;
    }
    for ( int i = 0 ; i <= 2 ; i++)
    {
        batching[step] += i;
        dfs(step+1);
        batching[step] -= i;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for ( int i = 1 ; i < 11 ; i++)
    {
        batching[i] = 1;
    }
    cin >> n;
    dfs(1);
    if (k == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << ans << endl;
        for ( int i = 1 ; i <= k-1 ; i++)
        {
            for ( int j = 1 ; j < 11 ; j++)
            {
                cout << book_batching[i][j] << " ";
            }
            cout << endl;
        }
    }

    system("pause");
    return 0;
}