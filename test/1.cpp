#include <windows.h>
#include <conio.h>
#include <cstdio>
/****** 光标移到指定位置 ********************************/
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
}
int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
	
	SetCursorPos(100,100);
	//gotoxy(hOut,20,30);         //光标定位在坐标（20,30）
	//printf("test");
	system("pause");
	return 0;
}
