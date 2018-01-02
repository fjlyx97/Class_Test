#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <cstdio>
using namespace std;
/** 
 * 作者：梁煜鑫
 * 日期：2018.1.2
 * 目的：推箱子小游戏
 * 版本号： Beta 0.1
 */

void hello();   //开始界面
void printMap(HANDLE hOut,char (*map)[81]);
void gotoxy(HANDLE hOut, int x, int y); //移动光标

int main()
{
    /* 取消光标 */
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /* 取消光标 */

    /*初始化区域*/
    srand(time(0));
    char map[31][81];

    hello();
    system("cls");
    printMap(hOut,map); //绘制地图

    system("pause");
    return 0;
}

void hello() //开始界面
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       推箱子       *\n");
    printf("                         *                    *\n");
    printf("                         * 请按任意键开始游戏 *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");
    getche();
    return;
}
void printMap(HANDLE hOut , char (*map)[81])
{
    int i , j;
    for (i = 1 ; i <= 300 ; i++)        //生成障碍物
    {
        map[rand()%30+1][rand()%80+1] = 5;
    }
    /*绘制地图边框*/
    for ( i = 0 ; i < 81 ; i++)
    {
        gotoxy(hOut,i,0);
        printf("#");
        map[0][i] = '#';
        gotoxy(hOut,i,30);
        printf("#");
        map[30][i] = '#';
    }
    for ( j = 0 ; j < 31 ; j++)
    {
        gotoxy(hOut,0,j);
        printf("#");
        map[j][0] = '#';
        gotoxy(hOut,80,j);
        printf("#");
        map[j][80] = '#';
    } 
    /*绘制障碍物*/
    for (i = 0 ; i < 31 ; i++)
    {
        for ( j = 0 ;  j < 81 ; j++)
        {
            if (map[i][j] == 5)
            {
                gotoxy(hOut,j,i);
                printf("%c",map[i][j]);
            }
        }
        printf("\n");
    }
    /*随机设置出口*/
    int temp = rand()%30+1;
    map[temp-1][80] = ' ';
    map[temp][80] = ' ';
    map[temp+1][80] = ' ';
    gotoxy(hOut,80,temp-1);
    printf(" ");
    gotoxy(hOut,80,temp);
    printf(" ");
    gotoxy(hOut,80,temp+1);
    printf(" ");
}
void gotoxy(HANDLE hOut, int x, int y)  //移动光标
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
      return;
}