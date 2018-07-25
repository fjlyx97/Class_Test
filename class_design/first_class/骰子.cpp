#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

void gotoxy(HANDLE hOut , int x , int y);//移动光标
void hello();   //开始界面
void printMap(HANDLE hOut,char status);   //绘制地图

class dice
{
public:
    int x;
    int y;
    int num;
    int x_speed;
    int y_speed;
public:
    void init_num();
};
void printDice(HANDLE hOut, dice* mydice);
void deleteDice(HANDLE hOut , dice* mydice);

int main()
{
    /*初始化*/
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    CONSOLE_CURSOR_INFO cci;    //取消光标
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);

    hello();//绘制欢迎界面
    system("cls");
    /* 初始化变量 */
    srand(time(0));
    char status;
    int i = 0;
    int loop_value;

    while (true)
    {
        if (i % 2 == 0)
        {
            status = 'A';
        }
        else
        {
            status = 'B';
        }
        printMap(hOut,status);//绘制地图
        getche();   //等待输入
        system("cls");
        printMap(hOut,status);//防止清屏

        dice* mydice = new dice;    //初始化成员
        dice* mydice1 = new dice;    //初始化成员
        mydice->init_num();         //初始化数字
        mydice1->init_num();         //初始化数字
        loop_value = 0;             //弹跳次数
        while (true)
        {
            printDice(hOut,mydice);
            printDice(hOut,mydice1);
            deleteDice(hOut,mydice);
            deleteDice(hOut,mydice1);


            mydice->y += mydice->y_speed;   //下落速度
            mydice->x += mydice->x_speed;   //横向平移速度
            mydice1->y += mydice1->y_speed;   //下落速度
            mydice1->x += mydice1->x_speed;   //横向平移速度

            mydice->y_speed += 1;           //下落加速
            mydice->x_speed += 1;           //横向加速
            mydice1->y_speed += 1;           //下落加速
            mydice1->x_speed += 1;           //横向加速

            if (mydice->y > 24)
            {
                mydice->y = 24;
                mydice->y_speed = -mydice->y_speed / 2;
            }
            if (mydice1->y > 24)
            {
                mydice1->y = 24;
                mydice1->y_speed = -mydice1->y_speed / 2;
            }

            if (mydice->x > 27)
            {
                mydice->x = 27;
                mydice->x_speed = -mydice->x_speed;
            }
            if (mydice1->x > 27)
            {
                mydice1->x = 27;
                mydice1->x_speed = -mydice1->x_speed;
            }

            if (mydice->x < 2)
            {
                mydice->x = 2;
            }
            if (mydice1->x < 2)
            {
                mydice1->x = 2;
            }

            if (loop_value > 20)
            { 
                mydice->y = 24; 
                mydice1->y = 24;
                break;
            }
            loop_value++;       //循环增加
        }
        printDice(hOut,mydice);
        printDice(hOut,mydice1);
        delete mydice;
        delete mydice1;
        mydice = NULL;
        mydice1 = NULL;
        i++;
    }
    system("pause");
    return 0;
}
/*绘制区域*/
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
}
void hello() //开始界面
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       投骰子       *\n");
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
void printMap(HANDLE hOut,char status) //绘制地图
{
    //纵20，横30
    for (int i = 5 ; i < 26 ; i++)
    {
        gotoxy(hOut,0,i);
        printf("%c",4);
        gotoxy(hOut,30,i);
        printf("%c",4);
        printf("\n");
    }
    for ( int i = 0 ; i < 31 ; i++)
    {
        printf("%c",4);
    }
    printf("\n");
    printf("玩家%c按任意键投骰子",status);
    return;
}

/*骰子功能区*/
void dice::init_num()   //初始化数据
{
    this->num = rand() % 6 + 1;
    this->x = rand() % 30 + 1;
    this->y = 5;
    this->x_speed = rand() % 10 + 1 - 5;
    this->y_speed = rand() % 5 + 1;
    return;
}
void printDice(HANDLE hOut , dice* mydice)
{
    mydice->num = rand() % 6 + 1;
    gotoxy(hOut,mydice->x-1,mydice->y-1);
    printf("###");
    gotoxy(hOut,mydice->x-1,mydice->y);
    printf("#%d#",mydice->num);
    gotoxy(hOut,mydice->x-1,mydice->y+1);
    printf("###");
    return;
}
void deleteDice(HANDLE hOut , dice* mydice)
{
    Sleep(20);
    gotoxy(hOut,mydice->x-1,mydice->y-1);
    printf("   ");
    gotoxy(hOut,mydice->x-1,mydice->y);
    printf("   ",mydice->num);
    gotoxy(hOut,mydice->x-1,mydice->y+1);
    printf("   ");
    return;
}