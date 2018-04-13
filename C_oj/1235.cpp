#include <iostream>
using namespace std;
int map[1001][1001] = {0};
int book[1001][1001] = {0};
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
    book[1][1] = 1;
    book[1][2] = 1;
    book[2][1] = 1;
    //for (int i = 1 ; i <= N ; i++)
    //{
    //    book[i][1] = i;
    //    book[1][i] = i;
    //}
    
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= M ; j++)
        {
            if (i == 1 && j == 1) continue;
            book[i][j] = book[i-1][j] + book[i][j-1];
        }
    }
    cout << book[X][Y] << endl;

    system("pause");
    return 0;
}