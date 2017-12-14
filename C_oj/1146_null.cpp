#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
long long map[3001][3001];
long long book[3001][3001];
char num[18];
long long dp(int i , int j ,int R)
{
    if (book[i][j] != -1)
    {
        return book[i][j];
    }
    if ( i == R )
    {
        book[i][j] = map[i][j];
    }
    else
    {
        long long x = dp(i+1,j,R);
        long long y = dp(i+1,j+1,R);
        book[i][j] = max<long long>(x,y) + map[i][j];
    }
    return book[i][j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int R;
    cin >> T;
    int c;
    long long result = 0;
    while (T--)
    {
        cin >> R;
        for (int i = 1 ; i <= R ; i++)
        {
            for (int j = 1 ; j <= R ; j++)
            {
                book[i][j] = -1;
            }
        }
        for (int i = 1 ; i <= R ; i++)
        {
            for (int j = 1 ; j <= i ; j++)
            {
                int k = 0;
                memset(num,'\0',sizeof(num));
                while ( (c = getchar()) != ' ' && c != EOF && c != '\n')
                {
                    num[k] = c;
                    k++;
                }
                map[i][j] = atoll(num);
            }
        }
        result = dp(1,1,R);
        cout << result << endl;
    }

    system("pause");
    return 0;
}