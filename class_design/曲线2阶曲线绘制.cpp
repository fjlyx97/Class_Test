#include <iostream>
#include <windows.h>
using namespace std;
void init_map(char (*map)[81]);
void gotoxy(HANDLE hOut , int x , int y);//移动光标
int main()
{
    int a0 , a1 , a2;   //获得曲线参数   
    int x , y;
    char map[24][81];  //初始化要绘制的地图
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    cout << "请输入a0,a1,a2三个参数：";
    cin >> a0 >> a1 >> a2;

    init_map(map);      //生成地图
    for (x = 0 ; x < 81 ; x++)
    {
        y = a0 + a1*(x-40) + a2*(x-40)*(x-40);
        if ((y > 21 || y < 0) && x < 40)
        {
            continue;
        }
        else if ((y > 21 || y < 0) && x > 40)
        {
            break;
        }
        map[23-y][x] = '*';
        gotoxy(hOut,x,23-y);
        cout << '*';
    }

    system("pause");
    return 0;
}
void init_map(char (*map)[81])
{
    int i , j;
    cout << endl;

    for (i = 0 ; i < 21 ; i++)
    {
        if ( i == 0)
        {
            for (j = 0 ; j < 39 ; j++)
            {
                cout << " ";
            }
            cout << "Y轴" << endl;
            continue;
        }
        for (j = 0 ; j < 40 ; j++)
        {
            cout << " ";
        }
        map[i][40] = '#';
        cout << map[i][40] << endl;
    }
    for ( i = 0 ; i < 81 ; i++)
    {
        map[20][i] = '#';
        cout << map[20][i];
    }
    cout << " X轴 " << endl;
    return;
}
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
}