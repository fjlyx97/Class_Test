#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int book[14] = {0};
int map[14];
int left_diagonal[50] = {0};
int right_diagonal[50] = {0};
int N;
int res = 0;
int book_num = 0;
void dfs(int step)
{
    if (step == N+1)
    {
        res++;
        if (book_num < 3)
        {
            book_num++;
            for ( int i = 1 ; i <= N ; i++)
            {
                cout << map[i] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 1 ; i <= N ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            map[step] = i;
            left_diagonal[step-map[step]+N] += 1;
            right_diagonal[step+map[step]] += 1;
            if (left_diagonal[step-map[step]+N] > 1)
            {
                book[i] = 0;
                left_diagonal[step-map[step]+N] -= 1;
                right_diagonal[step+map[step]] -= 1;
                continue;
            }
            else if (right_diagonal[step+map[step]] > 1)
            {
                book[i] = 0;
                left_diagonal[step-map[step]+N] -= 1;
                right_diagonal[step+map[step]] -= 1;
                continue;
            }
            dfs(step+1);
            book[i] = 0;
            left_diagonal[step-map[step]+N] -= 1;
            right_diagonal[step+map[step]] -= 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    dfs(1);
    cout << res << endl;
    system("pause");
    return 0;
}