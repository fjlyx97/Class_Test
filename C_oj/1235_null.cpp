#include <iostream>
using namespace std;
int map[1001][1001] = {0};
int book[1001][1001][2] = {0};  // 0 下 1 右
int main()
{
    int N , M , K , X , Y;
    int holex , holey;
    int startx = 1 , starty = 1;
    int ans = 0;
    // X Y 礼物坐标
    // N M 棋盘大小
    // 初始 1，1
    cin >> N >> M >> K >> X >> Y;
    for (int i = 1 ; i <=  K ; i++)
    {
        cin >> holex >> holey;
        map[holex][holey] = 1;
    }

    for (int i = 1 ; i <= M ; i++)
    {
        book[1][i][1] = 1;
    }
    for (int i = 1 ; i <= N ; i++)
    {
        book[i][1][0] = 1;
    }
    
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= M ; j++)
        {
            if (i == 1) continue;
            if (j == 1) continue;
            if (map[i][j] == 0 && book[i][j][0] == 0)
            {
                book[i][j][0] = book[i-1][j][0];
            }
            else
            {
                book[i][j][0] += book[i-1][j][0];
            }
            if (map[i][j] == 0 && book[i][j][1] == 0)
            {
                book[i][j][1] = book[i][j-1][1];
            }
            else
            {
                book[i][j][1] += book[i][j-1][1];
            }
            /*测试*/
            for (int m = 1 ; i <= N ; i++)
            {
                for (int k = 1 ; k <= M ; k++ )
                {
                    cout << book[m][k][0] << " ";
                }
                cout << endl;
            }
        }
    }
    cout << book[X][Y][0] + book[X][Y][1] << endl;
    system("pause");
    return 0;
}