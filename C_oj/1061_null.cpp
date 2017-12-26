#include <iostream>
using namespace std;
int num[201];
int min_add = 100;
int n , m;
int book[201][201] = {0};
void dp(int step, int m_add , int max)
{
    int temp = 0;
    if (step > n)
    {
        return;
    }
    if (max > min_add)
    {
        return;
    }
    if (m_add == m)
    {
        temp = book[1][n] - book[1][step-1];
        if (temp > max)
        {
            max = temp;
        }
        if (max < min_add)
        {
            min_add = max;
        }
        return;
    }
    for ( int i = 1 ; i < n ; i++)
    {
        temp = book[1][step+i-1] - book[1][step-1];
        if (temp > max)
        {
            max = temp;
        }
        dp(step+i,m_add+1,max);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
        book[1][i] = book[1][i-1] + num[i];
    } 
    int temp = 0;
    //for ( int i = 1 ; i < n ; i++)
    //{
    //    for ( int j = 1 ; j <= m ; j++)
    //    {
    //    }
    //}
    dp(1,1,0);
    cout << min_add << endl;
    system("pause");
    return 0;
}