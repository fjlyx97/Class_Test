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

/* 定义人物类 */
class people
{
public:
    int x;      //小人横坐标
    int y;      //小人纵坐标

public:
    /*小人初始化坐标*/
    void init_pos();
    /*小人的移动*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    /*绘制小人*/
    void print_pos(HANDLE hOut);
};

/* 定义箱子类 */
class box
{
public:
    /*横纵坐标定义*/
    int x;
    int y;
public:

    /*箱子操作定义*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    /*绘制箱子*/
    void print_pos(HANDLE hOut);
};


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

    while (true)
    {
        system("cls");
        printMap(hOut,map); //绘制地图
        people* mypeople = new people;  //初始化小人
        mypeople->init_pos();   //小人初始化位置

        if (map[mypeople->y][mypeople->x] == 5)
        {
            mypeople->init_pos();   //小人初始化位置
        }
        mypeople->print_pos(hOut);

        printf("123");
    }
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
    system("color A");                  //设置障碍物颜色
    for (i = 1 ; i <= 250 ; i++)        //生成障碍物
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
    int temp = rand()%28+2;
    map[temp-1][80] = ' ';
    map[temp][80] = ' ';
    map[temp+1][80] = ' ';
    gotoxy(hOut,80,temp-1);
    printf(" ");
    gotoxy(hOut,80,temp);
    printf(" ");
    gotoxy(hOut,80,temp+1);
    printf(" ");

    return;
}
void gotoxy(HANDLE hOut, int x, int y)  //移动光标
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
      return;
}

/*小人的参数*/
void people::init_pos()
{
    this->y = rand() % 30 + 1;
    this->x = rand() % 80 + 1;
    return;
}
/*绘制小人*/
void people::print_pos(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
    gotoxy(hOut,this->x,this->y);
    printf("%c",12);
    return;
}
/*小人的移动*/
void people::moveUp()
{
    this->y += 1;
    return;
}
void people::moveDown()
{
    this->y -= 1;
    return;
}
void people::moveRight()
{
    this->x += 1;
    return;
}
void people::moveLeft()
{
    this->x -= 1;
    return;
}

/* 箱子的参数 */
void box::moveUp()
{
    this->y += 1;
    return;
}
void box::moveDown()
{
    this->y -= 1;
    return;
}
void box::moveRight()
{
    this->x += 1;
    return;
}
void box::moveLeft()
{
    this->x -= 1;
    return;
}
void box::print_pos(HANDLE hOut)     //绘制箱子
{
    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
    gotoxy(hOut,this->x,this->y);
    printf("%c",12);
    return;
}