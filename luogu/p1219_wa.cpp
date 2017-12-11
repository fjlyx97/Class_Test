#include <iostream>
#include <cstring>
using namespace std;
int book[14];
int line_book[14][14];
int map[14];
int sum = 0;
void dfs(int step , int N)
{
    int flag = 1;
    int temp;
    int k;
    if ( step == N+1)
    {
        for ( int i = 2 ; i <= N ; i++)
        {
            temp = 0;
            k = i;
            for ( int j = 1 ; j <= i ; j++)
            {
                temp += line_book[j][k];   
                k--;
            }
            if (temp > 1)
            {
                flag = 0;
                return;
            }
        }
        for ( int i = N-1 ; i >= 1 ; i--)
        {
            temp = 0;
            k = i;
            for ( int j = 1 ; j <= N-i+1 ; j++)
            {
                temp += line_book[j][k];   
                k++;
            }
            if (temp > 1)
            {
                flag = 0;
                return;
            }
        }
        for ( int i = N-1 ; i >= 1 ; i--)
        {
            temp = 0;
            k = i;
            for ( int j = N ; j >= 1 ; j--)
            {
                temp += line_book[j][k];   
                k++;
            }
            if (temp > 1)
            {
                flag = 0;
                return;
            }
        }
        for ( int i = 2 ; i <= N ; i++)
        {
            temp = 0;
            k = i;
            for ( int j = N ; j >= 1 ; j--)
            {
                temp += line_book[j][k];   
                k--;
            }
            if (temp > 1)
            {
                flag = 0;
                return;
            }
        }
        if (flag)
        {
            sum++;
            if (sum <= 3)
            {
                for (int i = 1 ; i <= N ; i++)
                {
                    cout << map[i] << " ";
                }
                cout << endl;
            }
        }
        return;
    } 
    for ( int i = 1 ; i <= N ; i++)
    {
            if (book[i] == 0)
            {
                map[step] = i;
                book[i] = 1;
                line_book[step][i] = 1;
                dfs(step+1,N);
                book[i] = 0;
                line_book[step][i] = 0;
            }
    } 
   return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    dfs(1,N);
    cout << sum << endl;
    system("pause");
    return 0;
}