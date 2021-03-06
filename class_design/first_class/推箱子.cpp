#include <iostream>
#include <queue>
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

/* 定义箱子类 */
class box
{
public:
    /*横纵坐标定义*/
    int x;
    int y;
public:
    /*箱子初始化坐标*/
    void init_pos();

    /*箱子操作定义*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    /*绘制箱子*/
    void print_pos(HANDLE hOut);
    /*删除箱子*/
    void delete_pos(HANDLE hOut);
    /*移动箱子*/
    bool move_pos(char dir , char (*map)[81]);
    /*判断胜利*/
    bool if_win(int out_y);
};


/* 定义人物类 */
class people
{
public:
    int x;      //小人横坐标
    int y;      //小人纵坐标
    int step;   //小人已走步数

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
    /*删除小人*/
    void delete_pos(HANDLE hOut);
    /*移动小人*/
    void move_pos(char dir , char (*map)[81] , box** mybox);
};

void hello(HANDLE hOut , int* difficult);   //绘制开始界面
void printMap(HANDLE hOut,char (*map)[81],int* out_y,int difficult);    //绘制地图
void gotoxy(HANDLE hOut, int x, int y); //移动光标
void printPos(HANDLE hOut , people** mypeople);     //绘制人物位置
void printWin(HANDLE hOut);             //绘制胜利界面
bool judgePepBfs(people mypeople , char (*map)[81] , int out_y , HANDLE hOut);  //人物判断是否有解
bool judgeBoxBfs(box mybox , char (*map)[81] , int out_y , HANDLE hOut);        //箱子判断是否有解

int main()
{
    /* 取消光标 */
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);            //获得控制台句柄
    cci.bVisible = FALSE;                       //关闭光标
    SetConsoleCursorInfo(hOut,&cci);            //设置光标
    /* 取消光标 */

    /*初始化变量*/
    srand(time(0));
    char map[31][81];           //地图变量
    memset(map,0,sizeof(map));  //设置地图为空
    char dir;                   //移动的方向
    int out_y;                  //出口纵坐标
    int difficult = 0;          //难度设定

    while (true)
    {   
        /*初始化区域*/
        hello(hOut,&difficult);         //绘制欢迎界面
        system("cls");                  //清屏函数
        printMap(hOut,map,&out_y,difficult); //绘制地图

        /*小人初始化*/
        people* mypeople = new people;  //初始化小人
        mypeople->init_pos();   //小人初始化位置

        /*箱子初始化*/
        box* mybox = new box;
        mybox->init_pos();      //箱子初始化位置

        /*利用BFS判断地图是否有解*/
        int flag = 1;       //作为接下来判断地图是否有解的标志。
        while (true)
        {
            flag = 1;
            /*如果无解重新绘制地图*/
            if (judgeBoxBfs(*mybox,map,out_y,hOut) == false || judgePepBfs(*mypeople,map,out_y,hOut) == false)
            {
                system("cls");
                memset(map,0,sizeof(map));
                printMap(hOut,map,&out_y,difficult); //绘制地图
                mypeople->init_pos();   //小人初始化位置
                mybox->init_pos();
                flag = 0;
            }
            if (flag)
            {
                break;
            }
        }
        mypeople->print_pos(hOut);  //绘制小人
        mybox->print_pos(hOut);  //绘制箱子

        /* 游戏逻辑部分 */
        while (true)
        {
            printPos(hOut,&mypeople);   //每次循环绘制小人位置
            /*判断是否胜利*/
            if (mybox->if_win(out_y))
            {
                printWin(hOut);        //绘制胜利界面
                getch();
                delete mypeople;        //防止内存泄漏
                delete mybox;
                return 0;
            }
            /*判断方向*/
            dir = getch();
            mypeople->delete_pos(hOut);     //删除当前位置以便重新绘制
            mybox->delete_pos(hOut);
            mypeople->move_pos(dir,map,&mybox);     //小人移动
            
            /*绘制小人 箱子 位置*/
            mypeople->print_pos(hOut);      //重新绘制位置
            mybox->print_pos(hOut);         //重新绘制位置
        }
    }
}

void hello(HANDLE hOut , int* difficult) //开始界面
{
    int i , j = 30;
    printf("                         ************************************\n");
    printf("                         *                                  *\n");
    printf("                         *                                  *\n");
    printf("                         *                                  *\n");
    printf("                         *              推箱子              *\n");
    printf("                         *                                  *\n");
    printf("                         *     请按输入游戏难度：           *\n");
    printf("                         *                                  *\n");
    printf("                         *   难度对应障碍物数量（1-300）    *\n");
    printf("                         *                                  *\n");
    printf("                         *     无效输入默认难度为250        *\n");
    printf("                         *                                  *\n");
    printf("                         *                                  *\n");
    printf("                         ************************************\n");
    gotoxy(hOut,50,6);
    int difficult_temp;   //难度设置
    cin >> difficult_temp;
    if ( difficult_temp > 300 || difficult_temp < 1)
    {
        difficult_temp = 250;
    }
    *difficult = difficult_temp;
    system("cls");
    printf("                         ****************************\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         *  正在使用bfs算法生成地图 *\n");
    printf("                         *                          *\n");
    printf("                         *         请等待...        *\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         ****************************\n");
    
    for (i = 1 ; i <= 18 ; i++)
    {
        gotoxy(hOut,j,8);
        printf("%c",16);
        Sleep(200);
        j++;
    }
    return;
}
void printMap(HANDLE hOut , char (*map)[81] , int* out_y , int difficult)
{
    /* 0-30 0-80 */
    int i , j;
    system("color A");                  //设置障碍物颜色
    for (i = 1 ; i <= difficult ; i++)        //生成障碍物
    {
        map[rand()%29+1][rand()%79+1] = 5;
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
    *out_y = rand()%28+2;
    map[(*out_y)-1][80] = ' ';
    map[*out_y][80] = ' ';
    map[(*out_y)+1][80] = ' ';

    /*测试BFS*/
    //gotoxy(hOut,0,82);
    //for (int i = 0 ; i < 31 ; i++)
    //{
    //    for ( int j = 0 ; j < 81 ; j++)
    //    {
    //        cout << map[i][j];
    //    }
    //    cout << endl;
    //}
    //map[(*out_y)-1][79] = 5;
    //map[*out_y][79] = 5;
    //map[(*out_y)+1][79] = 5;
    //gotoxy(hOut,79,(*out_y)-1);
    //printf("%c",map[(*out_y)-1][79]);
    //gotoxy(hOut,79,(*out_y));
    //printf("%c",map[*out_y][79]);
    //gotoxy(hOut,79,(*out_y)+1);
    //printf("%c",map[(*out_y)+1][79]);
    /*测试BFS*/

    gotoxy(hOut,80,(*out_y)-1);
    printf(" ");
    gotoxy(hOut,80,*out_y);
    printf(" ");
    gotoxy(hOut,80,(*out_y)+1);
    printf(" ");

    /* 绘制按键说明 */
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);     //设置字体颜色
    gotoxy(hOut,85,18);
    printf("使用W,S,A,D进行移动");
    gotoxy(hOut,85,20);
    printf("回车键退出游戏");
    gotoxy(hOut,85,22);
    printf("%c代表小人,%c代表箱子",12,30);
    return;
}
void printPos(HANDLE hOut , people** mypeople)      //绘制人物位置
{
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    gotoxy(hOut,85,10);
    printf("当前人物位置为：%d,%d",(*mypeople)->x,(*mypeople)->y);
    gotoxy(hOut,85,12);
    printf("当前人物已走步数为:%d",(*mypeople)->step);
    return;
}
void printWin(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
    gotoxy(hOut,85,14);
    printf("您已获得胜利，按任意键退出游戏。");
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
bool judgePepBfs(people mypeople , char (*map)[81], int out_y , HANDLE hOut)      //利用BFS算法判断当前地图是否有解
{
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //小人移动方法
    int book[31][81];                         //记录位置
    memset(book,0,sizeof(book));

    queue<people> myqueue;                          //生成队列
    book[mypeople.y][mypeople.x] = 1;
    myqueue.push(mypeople);

    int tempx , tempy;
    //mypeople.print_pos(hOut);     //测试

    while (!myqueue.empty())
    {
        for ( int i = 0 ; i < 4 ; i++)
        {
            tempx = myqueue.front().x + next[i][1];
            tempy = myqueue.front().y + next[i][0];
            if (book[tempy][tempx] == 0 && map[tempy][tempx] == '\0')
            {
                book[tempy][tempx] = 1;
                people tempPeople;
                tempPeople.x = tempx;
                tempPeople.y = tempy;
                //tempPeople.print_pos(hOut);       //测试
                myqueue.push(tempPeople);
            }
            if (tempx == 80 && (tempy == out_y || tempy == out_y-1 || tempy == out_y+1))
            {
                return true;
            }
        }
        myqueue.pop();
    }
    return false;
}
bool judgeBoxBfs(box mybox , char (*map)[81] , int out_y , HANDLE hOut)
{
    /*初始判断*/
    if (map[mybox.y][mybox.x+1] == '#' || map[mybox.y][mybox.x+1] == 5)
    {
        return false;
    }
    else if (map[mybox.y][mybox.x-1] == '#' || map[mybox.y][mybox.x-1] == 5)
    {
        return false;
    }
    else if (map[mybox.y+1][mybox.x] == '#' || map[mybox.y+1][mybox.x] == 5)
    {
        return false;
    }
    else if (map[mybox.y-1][mybox.x] == '#' || map[mybox.y-1][mybox.x] == 5)
    {
        return false;
    }

    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //小人移动方法
    int book[31][81];                         //记录位置
    memset(book,0,sizeof(book));

    queue<box> myqueue;                          //生成队列
    book[mybox.y][mybox.x] = 1;
    myqueue.push(mybox);

    int tempx , tempy;
    //mybox.print_pos(hOut);     //测试

    while (!myqueue.empty())
    {
        for ( int i = 0 ; i < 4 ; i++)
        {
            tempx = myqueue.front().x + next[i][1];
            tempy = myqueue.front().y + next[i][0];
            if (book[tempy][tempx] == 0 && map[tempy][tempx] == '\0')
            {
                book[tempy][tempx] = 1;
                box tempbox;
                tempbox.x = tempx;
                tempbox.y = tempy;
                //tempbox.print_pos(hOut);       //测试
                myqueue.push(tempbox);
            }
            if (tempx == 80 && (tempy == out_y || tempy == out_y-1 || tempy == out_y+1))
            {
                return true;
            }
        }
        myqueue.pop();
    }
    return false;
}
/*小人的参数*/
void people::init_pos()
{
    this->y = rand() % 29 + 1;
    this->x = rand() % 79 + 1;
    this->step = 0;
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
/*删除小人*/
void people::delete_pos(HANDLE hOut)
{
    gotoxy(hOut,this->x,this->y);
    printf(" ");
    return;
}
/*小人的移动*/
void people::moveUp()
{
    this->y -= 1;
    return;
}
void people::moveDown()
{
    this->y += 1;
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
/* 小人推箱子移动 */
void people::move_pos(char dir , char (*map)[81] , box** mybox)
{
    int flag = 1;
    if (dir == 'w')
    {
        this->moveUp();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveDown();
            flag = 0;
        }
        if (this->x == (*mybox)->x && this->y == (*mybox)->y)
        {
            if (!(*mybox)->move_pos(dir,map))
            {
                this->moveDown();
                flag = 0;
            }
        }
    }
    else if (dir == 's')
    {
        this->moveDown();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveUp();
            flag = 0;
        }
        if (this->x == (*mybox)->x && this->y == (*mybox)->y)
        {
            if (!(*mybox)->move_pos(dir,map))
            {
                this->moveUp();
                flag = 0;
            }
        }
    }
    else if (dir == 'a')
    {
        this->moveLeft();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveRight();
            flag = 0;
        }
        if (this->x == (*mybox)->x && this->y == (*mybox)->y)
        {
            if (!(*mybox)->move_pos(dir,map))
            {
                this->moveRight();
                flag = 0;
            }
        }
    }
    else if (dir == 'd')
    {
        this->moveRight();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveLeft();
            flag = 0;
        }
        if (this->x == (*mybox)->x && this->y == (*mybox)->y)
        {
            if (!(*mybox)->move_pos(dir,map))
            {
                this->moveLeft();
                flag = 0;
            }
        }
    }
    else if (dir == '\r')
    {
        exit(0);
    }
    if (flag)
    {
        this->step++;
    }
    return;
}
/* 箱子的参数 */
void box::moveUp()
{
    this->y -= 1;
    return;
}
void box::moveDown()
{
    this->y += 1;
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
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
    gotoxy(hOut,this->x,this->y);
    printf("%c",30);
    return;
}
void box::init_pos()     //初始化箱子位置
{
    this->y = rand() % 29 + 1;
    this->x = rand() % 79 + 1;
    return;
}
void box::delete_pos(HANDLE hOut)
{
    gotoxy(hOut,this->x,this->y);
    printf(" ");
    return;
}
bool box::move_pos(char dir ,char (*map)[81])
{
    if (dir == 'w')
    {
        this->moveUp();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveDown();
            return false;
        }
    }
    else if (dir == 's')
    {
        this->moveDown();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveUp();
            return false;
        }
    }
    else if (dir == 'a')
    {
        this->moveLeft();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveRight();
            return false;
        }
    }
    else if (dir == 'd')
    {
        this->moveRight();
        if (map[this->y][this->x] == '#' || map[this->y][this->x] == 5)
        {
            this->moveLeft();
            return false;
        }
    }
    return true;
}
bool box::if_win(int out_y)
{
    if (this->x == 80 && (this->y == out_y || this->y == out_y-1 || this->y == out_y+1))
    {
        return true;
    }
    else
    {
        return false;
    }
}