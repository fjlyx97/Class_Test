#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int e[10001][10001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M;
    int A , B , C;
    while ( cin >> N >> M)
    {
        if (N == 0 && M == 0)
        {
            break;
        }
        for (int i = 1 ; i <= M ; i++)
        {
            cin >> A >> B >> C;
            e[A][B] = C;
            e[B][A] = C;
        }
        for (int k = 1 ; k <= N ; k++)
        {
            for (int i = 1 ; i <= N ; i++)
            {
                for (int j = 1 ; j <= N ; j++)
                {
                    if (e[i][k]+e[k][j] < e[i][j])
                    {
                        e[i][j] = e[i][k]+e[k][j];
                    }
                }
            }
        }
        for (int i = 1 ; i <= N ;i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                cout << e[i][j] << " ";
            }
            cout << endl;
        }
        cout << e[1][N] << endl;
    }



    system("pause");
    return 0;
}