#include <iostream>
using namespace std;
inline int max(int a , int b)
{
    return a>b?a:b;
}
int map[10][10] = {0};
int book[10][10][10][10] = {0};
int main()
{
    int N;
    int i , j , num;
    cin >> N;
    while(true)
    {
        cin >> i >> j >> num;
        if (i == 0 && j == 0 && num == 0)
        {
            break;
        }
        map[i][j] = num;
    }
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= N ; j++)
        {
            for (int k = 1 ; k <= N ; k++)
            {
                for (int l = 1 ; l <= N ; l++)
                {
                    book[i][j][k][l] = max(book[i][j-1][k][l-1] ,
                                       max(book[i][j-1][k-1][l] ,
                                       max(book[i-1][j][k][l-1] ,
                                       book[i-1][j][k-1][l]))) + map[i][j] + map[k][l];
                    if (i == k && j == l)
                    {
                        book[i][j][k][l] -= map[i][j];
                    }
                }
            }
        }
    }
    cout << book[N][N][N][N] << endl;
    system("pause");
    return 0;
}