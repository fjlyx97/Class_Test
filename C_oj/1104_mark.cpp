#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 11;
int num[max_n][max_n];
int book[max_n][max_n];
int result = 0;
int dp(int i , int j , int N , int num[][max_n])
{
    if (book[i][j] != -1)
    {
        return book[i][j];
    }
    if ( i == N-1 )
    {
        book[i][j] = num[i][j];
    }
    else
    {
        int x = dp(i+1,j,N,num);
        int y = dp(i+1,j+1,N,num);
        book[i][j] = min(x,y) + num[i][j];
    }
    return book[i][j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    for (int i = 0 ; i < max_n ; i++)
    {
        for (int j = 0 ; j< max_n ; j++)
        {
            book[i][j] = -1;
            num[i][j] = -1;
        }
    }
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            cin >> num[i][j];
        }
    }

    int result = dp(0,0,N,num);
    cout << result << endl;
    system("pause");
    return 0;
}