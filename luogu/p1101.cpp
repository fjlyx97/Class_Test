#include <iostream>
#include <cstring>
using namespace std;
char map[101][101];
int book[101][101];
int n;
char str_temp[8];
void dfs()
{
    int flag;
    int l;
    for ( int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (map[i][j] == 'y')
            {
                if ( j+6 <= n)//右边
                {
                    l = 0;
                    for ( int k = j ; k <= j+6 ; k++)
                    {
                        str_temp[l] = map[i][k];
                        l++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        for ( int k = j ; k <= j+6 ; k++)
                        {
                            book[i][k] = 1;
                        }
                    }
                }
                if ( j-6 >= 1)//左边
                {
                    l = 0;
                    for ( int k = j ; k >= j-6 ; k--)
                    {
                        str_temp[l] = map[i][k];
                        l++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        for ( int k = j ; k >= j-6 ; k--)
                        {
                            book[i][k] = 1;
                        }
                    }
                }
                if ( i+6 <= n)//下面
                {
                    l = 0;
                    for ( int k = i ; k <= i+6 ; k++)
                    {
                        str_temp[l] = map[k][j];
                        l++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        for ( int k = i ; k <= i+6 ; k++)
                        {
                            book[k][j] = 1;
                        }
                    }
                }
                if ( i-6 >= 1)//上面
                {
                    l = 0;
                    for ( int k = i ; k >= i-6 ; k--)
                    {
                        str_temp[l] = map[k][j];
                        l++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        for ( int k = i ; k >= i-6 ; k--)
                        {
                            book[k][j] = 1;
                        }
                    }
                }
                if ( i+6 <= n && j+6 <= n)//左上到右下
                {
                    l = 0;
                    int k = i;
                    int m = j;
                    for ( ; k <= i+6 ; )
                    {
                        str_temp[l] = map[k][m];
                        l++;
                        k++;
                        m++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        int k = i;
                        int m = j;
                        for ( ; k <= i+6 ; )
                        {
                            book[k][m] = 1;
                            k++;
                            m++;
                        }
                    }
                }
                if ( i+6 <= n && j-6 >= 1)//右上到左下
                {
                    l = 0;
                    int k = i;
                    int m = j;
                    for ( ; m >= j-6 ; )
                    {
                        str_temp[l] = map[k][m];
                        l++;
                        k++;
                        m--;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        int k = i;
                        int m = j;
                        for ( ; m >= j-6 ; )
                        {
                            book[k][m] = 1;
                            k++;
                            m--;
                        }
                    }
                }
                if ( i-6 >= 1 && j+6 <= n)//左下到右上
                {
                    l = 0;
                    int k = i;
                    int m = j;
                    for ( ; k >= i-6 ; )
                    {
                        str_temp[l] = map[k][m];
                        l++;
                        k--;
                        m++;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        int k = i;
                        int m = j;
                        for ( ; k >= i-6 ; )
                        {
                            book[k][m] = 1;
                            k--;
                            m++;
                        }
                    }
                }
                if ( i-6 >= 1 && j-6 >= 1)//右下到左上
                {
                    l = 0;
                    int k = i;
                    int m = j;
                    for ( ; m >= j-6 ; )
                    {
                        str_temp[l] = map[k][m];
                        l++;
                        k--;
                        m--;
                    }
                    if (!strcmp(str_temp,"yizhong"))
                    {
                        int k = i;
                        int m = j;
                        for ( ; m >= j-6 ; )
                        {
                            book[k][m] = 1;
                            k--;
                            m--;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(book,0,sizeof(book));
    cin >> n;
    for ( int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs();
    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= n ; j++)
        {
            if (book[i][j] == 1)
            {
                cout << map[i][j];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}