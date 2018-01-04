#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

/** 
 * 作者：梁煜鑫
 * 日期：2018.1.1
 * 目的：贪吃蛇小游戏
 * 版本号： Beta 0.1
 */

using namespace std;

void gotoxy(HANDLE hOut, int x, int y); //移动光标
void hello();   //开始界面
void over();    //结束界面
void printMap(HANDLE hOut); //绘制地图

class snake
{
private:
    int snake_x;  //蛇横坐标
    int snake_y;  //蛇纵坐标
    int snake_len;      //蛇的长度
public:
    snake* next;  //下一节蛇的身体

public:
    /*蛇的构造函数*/
    snake(int x , int y , int len)
    { 
        this->snake_x = x; 
        this->snake_y = y; 
        this->snake_len = len;
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
    int return_len();//返回长度
    void add_len();//增加长度
    friend void printsnake(HANDLE hOut,snake* snake_head); //画蛇
    friend void Dprintsnake(HANDLE hOut,snake* snake_head); //画蛇
    friend void movesnake(snake* snake_head , char dir);//移动蛇
    friend snake* new_snake(snake* snake_end);//生成新的蛇
    friend void delete_snake(snake* snake_head);//删除蛇
    friend bool snake_cash(snake* snake_head);        //蛇是否撞到自己
};
void printsnake(HANDLE hOut,snake* snake_head); //画蛇
void Dprintsnake(HANDLE hOut,snake* snake_head); //画蛇
void movesnake(snake* snake_head , char dir);   //蛇的移动
snake* new_snake(snake* snake_end);//生成新的蛇
void delete_snake(snake* snake_head);//删除蛇
bool snake_cash(snake* snake_head);        //蛇是否撞到自己
void printScore(HANDLE hOut,snake* snake_head); //绘制蛇分数

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
    char temp_dir;
    char status;
    int difficult;    //难度设置
    /* 初始化区域 */
    while (true)
    {
        /*初始化蛇头*/
        snake* mysnake = new snake(rand()%54+1,rand()%26+1,1);
        snake* snake_head = mysnake;
        snake* snake_end = mysnake;
        printsnake(hOut,mysnake);
        dir = '\0';
        temp_dir = '\0';
        status = '\0';
        difficult = 150;

        /*初始化食物*/
        food* myfood = new food;
        myfood->show_food();

        system("cls");
        while(true)
        {
            /*清屏*/
            Dprintsnake(hOut,snake_head);

            /*读取键盘输入*/
            if (kbhit())
            {
                temp_dir = dir;
                dir = getch();
                if (temp_dir == 'w' && dir == 's')
                {
                    dir = 'w';
                }
                if (temp_dir == 's' && dir == 'w')
                {
                    dir = 's';
                }
                if (temp_dir == 'a' && dir == 'd')
                {
                    dir = 'a';
                }
                if (temp_dir == 'd' && dir == 'a')
                {
                    dir = 'd';
                }
            }
            snake_head = mysnake;
            
            /*判断状态*/
            //蛇吃食物
            if (snake_head->return_x() == myfood->return_food_x() && snake_head->return_y() == myfood->return_food_y() )
            {
                myfood->show_food();//重新生成食物
                snake_head->add_len();
                snake_end = new_snake(snake_end);
            }
            //蛇是否撞到自己
            
            //蛇撞墙
            if ((snake_head->return_x() == 0) || (snake_head->return_x() == 55) || (snake_head->return_y() == 0) || (snake_head->return_y() == 27) || snake_cash(snake_head))
            {
                system("cls");
                over();
                status = getche();
                if (status == '\r')
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }

            /*绘制区域*/
            movesnake(snake_head,dir);
            printMap(hOut);
            printsnake(hOut,snake_head);
            printScore(hOut,snake_head);
            myfood->print_food(hOut);

            printMap(hOut); //防闪烁
            /*难度设置*/
            Sleep(difficult);
        }
        /* 清空内存 */
        delete_snake(snake_head);
        delete myfood;
        snake_head = NULL;
        snake_end = NULL;
        mysnake = NULL;
        myfood = NULL;

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
void over()
{   printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       贪吃蛇       *\n");
    printf("                         *                    *\n");
    printf("                         *      游戏结束      *\n");
    printf("                         *                    *\n");
    printf("                         *   按回车重新开始   *\n");
    printf("                         *   其他键退出游戏   *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");

}
void printMap(HANDLE hOut)
{
    // 地图大小 横56 纵28
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
void printScore(HANDLE hOut,snake* snake_head) //绘制分数
{
    gotoxy(hOut,60,14);
    printf("当前得分为：%d",(snake_head->return_len()-1)*100);
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
void Dprintsnake(HANDLE hOut,snake* snake_head) //删除蛇
{
    snake* snake_temp = snake_head;
    while (snake_temp != NULL)
    {
        gotoxy(hOut,snake_temp->snake_x,snake_temp->snake_y);
        printf(" ");
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
    int tempx = snake_head->return_x();
    int tempy = snake_head->return_y();
    int tempx_1;
    int tempy_1;
    snake* snake_temp = snake_head;
    while (snake_temp->next != NULL)
    {
        tempx_1 = snake_temp->next->snake_x;
        tempy_1 = snake_temp->next->snake_y;
        snake_temp->next->snake_x = tempx;
        snake_temp->next->snake_y = tempy;
        tempx = tempx_1;
        tempy = tempy_1;
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
int snake::return_len()//返回长度
{
    return this->snake_len;
}
void snake::add_len()
{
    this->snake_len++;
    return;
}
snake* new_snake(snake* snake_end)  //生成蛇
{
    int x = snake_end->return_x();
    int y = snake_end->return_y();
    snake* new_snake = new snake(x,y,1);
    snake_end->next = new_snake;
    snake_end = snake_end->next;
    return snake_end;
}
void delete_snake(snake* snake_head)//删除蛇
{
    snake* snake_temp;
    while (snake_head != NULL)
    {
        snake_temp = snake_head;
        snake_head = snake_head->next;
        delete snake_temp;
    }
}
bool snake_cash(snake* snake_head)        //蛇是否撞到自己
{
    if (snake_head->snake_len > 2)
    {
        snake* snake_temp = snake_head->next->next;
        while(snake_temp != NULL)
        {
            if (snake_head->snake_x == snake_temp->snake_x && snake_head->snake_y == snake_temp->snake_y)
            {
                return true;
            }
            snake_temp = snake_temp->next;
        }
        return false;
    }
    return false;
}
/*蛇的定义*/

/*食物的定义*/

void food::show_food()  //生成食物
{
    this->food_x = rand() % 54+1;
    this->food_y = rand() % 26+1;
    return;
}
void food::print_food(HANDLE hOut)  //绘制食物
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