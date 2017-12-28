#include <iostream>
using namespace std;
int is_primer[31] = {0};
int book[13] = {0};
int num[13] = {0};
int n;
void dfs(int step)
{
    if (num[1] > 1 )
    {
        return;
    }
    if (step == n+1)
    {
        if (is_primer[num[step-1]+num[1]])
        {
            for ( int i = 1 ; i <= n ; i++)
            {
                cout << num[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for ( int i = 1 ; i <= n ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            num[step] = i;
            if (step >= 2 && is_primer[num[step]+num[step-1]] == 0)
            {
                book[i] = 0;
                continue;
            }
            dfs(step+1);
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 3 ; i <= 30 ; i++)
    {
        int flag = 1;
        for ( int j = 2 ;  j < i ; j++)
        {
            if ( i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            is_primer[i] = 1;
        }
    }
    is_primer[2] = 1;
    cin >> n;
    dfs(1);
    system("pause");
    return 0;
}