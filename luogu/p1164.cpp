#include <iostream>
using namespace std;
#define max(a,b) a>b?a:b
int order[101] = {0};
int book[101][10001] = {0};
int N , M;
int main()
{
    cin >> N >> M;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> order[i];
    }
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= M ; j++)
        {
            if (j == order[i])
            {
                book[i][j] = book[i-1][j] + 1;
            }
            else if (j > order[i])
            {
                book[i][j] = book[i-1][j] + book[i-1][j-order[i]];
            }
            else if (j < order[i])
            {
                book[i][j] = book[i-1][j];
            }
        }
    }
    cout << book[N][M] << endl;
    system("pause");
    return 0;
}