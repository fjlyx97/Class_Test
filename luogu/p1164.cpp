#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int menu[101];
int book[101][10001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char str[10];
    int N , M;
    cin >> N >> M;
    for ( int i = 1 ; i <= N ; i++)
    {
        cin >> menu[i];
    }
    for (int i = 1 ; i <= N ; i++)
    {
        for ( int j = M ; j > 0 ; j--)
        {
            if ( j >= menu[i] )
            {
                book[i][j] += book[i-1][j-menu[i]]+1;
            }
            else
            {
                book[i][j] = book[i-1][j];
            }
        }
    }
    cout << book[N][M] << endl;
    system("pause");
    return 0;
}