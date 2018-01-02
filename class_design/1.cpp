#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
void initMap(HANDLE hOut , char (*map)[31]);
void gotoxy(HANDLE hOut , int x , int y);//移动光标
int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char map[31][31];
    initMap(hOut,map);
    system("pause");
    return 0;
}
void initMap(HANDLE hOut , char (*map)[31])  //初始化地图
{
    int y;
    for (int x = 1 ; x < 31 ; x++)
    {
        y = sqrt((31*31)- (x*x));
        gotoxy(hOut,x,31-y);
        cout << '*';
    }
}
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
}