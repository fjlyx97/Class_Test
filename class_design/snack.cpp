#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(HANDLE hOut, int x, int y); //移动光标
void hello();   //开始界面
void printMap(HANDLE hOut);

class snake
{
private:
    int snake_x;  //蛇横坐标
    int snake_y;  //蛇纵坐标
public:
    snake* next;  //下一节蛇的身体

public:
    /*蛇的构造函数*/
    snake(int x , int y)
    { 
        this->snake_x = x; 
        this->snake_y = y; 
        this->next = NULL;
    }

    /*蛇的移动*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    /*蛇的其他操作*/
    int return_x();//返回横坐标
    int return_y();//返回纵坐标
    friend void printsnake(HANDLE hOut,snake* snake_head); //画蛇
    friend void movesnake(snake* snake_head , char dir);//友元函数
    friend snake* new_snake(snake* snake_end);//生成新的蛇
};
void printsnake(HANDLE hOut,snake* snake_head); //画蛇
void movesnake(snake* snake_head , char dir);   //蛇的移动
snake* new_snake(snake* snake_end);//生成新的蛇

class food
{
private:
    int food_x;
    int food_y;

public:
    void show_food();//出现食物
    void print_food(HANDLE hOut);//绘制食物
    int return_food_x();//返回横坐标
    int return_food_y();//返回纵坐标
};

int main()
{
    /* 取消光标 */
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /* 取消光标 */
    
    /* 初始化区域 */
    srand(time(0));
    hello();
    char dir;
    /* 初始化区域 */
    while (true)
    {
        /*初始化蛇头*/
        snake* mysnake = new snake(rand()%55+1,rand()%27+1);
        snake* snake_end = mysnake;
        printsnake(hOut,mysnake);

        /*初始化食物*/
        food* myfood = new food;
        myfood->show_food();

        while(true)
        {
            /*清屏*/
            system("cls");

            /*读取键盘输入*/
            if (kbhit())
            {
                dir = getch();
            }
            snake* snake_head = mysnake;
            
            /*判断状态*/
            if (snake_head->return_x() == myfood->return_food_x() && snake_head->return_y() == myfood->return_food_y())
            {
                myfood->show_food();//重新生成食物
                snake_end = new_snake(snake_end);
            }
            /*绘制区域*/
            movesnake(snake_head,dir);
            printMap(hOut);
            printsnake(hOut,snake_head);
            myfood->print_food(hOut);

            //while (snake_head != NULL)
            //{
            //    snake_head->printsnake(hOut,snake_head);
            //    snake_head = snake_head->next;
            //}

            //printMap(hOut);
            Sleep(200);
        }
    }
    system("pause");
    return 0;
}
void hello() //开始界面
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       贪吃蛇       *\n");
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
void printMap(HANDLE hOut)
{
    // 地图大小 横55 纵28
    gotoxy(hOut,0,0);
    printf("########################################################\n");   
    for ( int i = 1 ; i <= 26 ; i++)
    {
        gotoxy(hOut,0,i);
        printf("#");
        gotoxy(hOut,55,i);
        printf("#\n");
    }
    printf("########################################################\n");   
    return;
}
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //横坐标
      pos.Y = y;            //纵坐标
      SetConsoleCursorPosition(hOut, pos);
      return;
}
/*蛇的定义*/
void printsnake(HANDLE hOut,snake* snake_head)
{
    snake* snake_temp = snake_head;
    while (snake_temp != NULL)
    {
        gotoxy(hOut,snake_temp->snake_x,snake_temp->snake_y);
        printf("%c",1);
        snake_temp = snake_temp->next;
    }
    return;
}
void snake::moveUp()
{
    this->snake_y -= 1;
    return;
}
void snake::moveDown()
{
    this->snake_y += 1;
    return;
}
void snake::moveLeft()
{
    this->snake_x -= 1;
    return;
}
void snake::moveRight()
{
    this->snake_x += 1;
    return;
}
void movesnake(snake* snake_head , char dir)
{
    snake* snake_temp = snake_head;
    int temp_x;
    int temp_y;
    while(snake_temp->next != NULL)
    {
        temp_x = snake_temp->next->snake_x;
        temp_y = snake_temp->next->snake_y;
        snake_temp->next->snake_x = snake_temp->snake_x;               
        snake_temp->next->snake_y = snake_temp->snake_y;               
        snake_temp = snake_temp->next;
    }
    switch (dir)
    {
        case 'w':
            snake_head->moveUp();
            break;
        case 's':
            snake_head->moveDown();
            break;
        case 'a':
            snake_head->moveLeft();
            break;
        case 'd':
            snake_head->moveRight();
            break;
    }
    return;
}
int snake::return_x()
{
    return this->snake_x;
}
int snake::return_y()
{
    return this->snake_y;
}
snake* new_snake(snake* snake_end)
{
    int x = snake_end->return_x()-3;
    int y = snake_end->return_y()-3;
    snake* new_snake = new snake(x,y);
    snake_end->next = new_snake;
    snake_end = snake_end->next;
    return snake_end;
}
/*蛇的定义*/

/*食物的定义*/
void food::show_food()
{
    this->food_x = rand() % 55+1;
    this->food_y = rand() % 27+1;
    return;
}
void food::print_food(HANDLE hOut)
{
    gotoxy(hOut,this->food_x,this->food_y);
    printf("%c",3);
    return;
}
int food::return_food_x()
{
    return this->food_x;
}
int food::return_food_y()
{
    return this->food_y;
}
/*食物的定义*/
