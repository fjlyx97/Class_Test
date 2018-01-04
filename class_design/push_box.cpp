#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <cstdio>
using namespace std;
/** 
 * ���ߣ�������
 * ���ڣ�2018.1.2
 * Ŀ�ģ�������С��Ϸ
 * �汾�ţ� Beta 0.1
 */

/* ���������� */
class box
{
public:
    /*�������궨��*/
    int x;
    int y;
public:
    /*���ӳ�ʼ������*/
    void init_pos();

    /*���Ӳ�������*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    /*��������*/
    void print_pos(HANDLE hOut);
    /*ɾ������*/
    void delete_pos(HANDLE hOut);
    /*�ƶ�����*/
    bool move_pos(char dir , char (*map)[81]);
    /*�ж�ʤ��*/
    bool if_win(int out_y);
};


/* ���������� */
class people
{
public:
    int x;      //С�˺�����
    int y;      //С��������
    int step;   //С�����߲���

public:
    /*С�˳�ʼ������*/
    void init_pos();
    /*С�˵��ƶ�*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    /*����С��*/
    void print_pos(HANDLE hOut);
    /*ɾ��С��*/
    void delete_pos(HANDLE hOut);
    /*�ƶ�С��*/
    void move_pos(char dir , char (*map)[81] , box** mybox);
};

void hello(HANDLE hOut);   //��ʼ����
void printMap(HANDLE hOut,char (*map)[81],int* out_y);
void gotoxy(HANDLE hOut, int x, int y); //�ƶ����
void printPos(HANDLE hOut , people** mypeople);
void printWin(HANDLE hOut);
bool judgePepBfs(people mypeople , char (*map)[81] , int out_y , HANDLE hOut);
bool judgeBoxBfs(box mybox , char (*map)[81] , int out_y , HANDLE hOut);

int main()
{
    /* ȡ����� */
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /* ȡ����� */

    /*��ʼ������*/
    srand(time(0));
    char map[31][81];
    memset(map,0,sizeof(map));
    char dir;
    int out_y;

    while (true)
    {   
        /*��ʼ������*/
        hello(hOut);
        system("cls");
        printMap(hOut,map,&out_y); //���Ƶ�ͼ

        /*С�˳�ʼ��*/
        people* mypeople = new people;  //��ʼ��С��
        mypeople->init_pos();   //С�˳�ʼ��λ��

        /*���ӳ�ʼ��*/
        box* mybox = new box;
        mybox->init_pos();

        /*����BFS�жϵ�ͼ�Ƿ��н�*/
        while (!judgePepBfs(*mypeople,map,out_y,hOut) && !judgeBoxBfs(*mybox,map,out_y,hOut))
        {
            system("cls");
            memset(map,0,sizeof(map));
            printMap(hOut,map,&out_y); //���Ƶ�ͼ
            mypeople->init_pos();   //С�˳�ʼ��λ��
            mybox->init_pos();
        }

        mypeople->print_pos(hOut);  //����С��
        mybox->print_pos(hOut);  //��������

        /* ��Ϸ�߼����� */
        while (true)
        {
            printPos(hOut,&mypeople);
            /*�ж��Ƿ�ʤ��*/
            if (mybox->if_win(out_y))
            {
                printWin(hOut);        //����ʤ������
                getch();
                delete mypeople;
                delete mybox;
                return 0;
            }
            /*�жϷ���*/
            dir = getch();
            mypeople->delete_pos(hOut);
            mybox->delete_pos(hOut);
            mypeople->move_pos(dir,map,&mybox);     //С���ƶ�
            
            /*����С�� ���� λ��*/
            mypeople->print_pos(hOut);
            mybox->print_pos(hOut);
        }
    }
}

void hello(HANDLE hOut) //��ʼ����
{
    int i , j = 30;
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       ������       *\n");
    printf("                         *                    *\n");
    printf("                         * �밴�������ʼ��Ϸ *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");
    getche();
    system("cls");
    printf("                         ****************************\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         *                          *\n");
    printf("                         *  ����ʹ��bfs�㷨���ɵ�ͼ *\n");
    printf("                         *                          *\n");
    printf("                         *         ��ȴ�...        *\n");
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
void printMap(HANDLE hOut , char (*map)[81] , int* out_y)
{
    /* 0-30 0-80 */
    int i , j;
    system("color A");                  //�����ϰ�����ɫ
    for (i = 1 ; i <= 250 ; i++)        //�����ϰ���
    {
        map[rand()%29+1][rand()%79+1] = 5;
    }

    /*���Ƶ�ͼ�߿�*/
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
    /*�����ϰ���*/
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
    /*������ó���*/
    *out_y = rand()%28+2;
    map[(*out_y)-1][80] = ' ';
    map[*out_y][80] = ' ';
    map[(*out_y)+1][80] = ' ';

    /*����BFS*/
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
    /*����BFS*/

    gotoxy(hOut,80,(*out_y)-1);
    printf(" ");
    gotoxy(hOut,80,*out_y);
    printf(" ");
    gotoxy(hOut,80,(*out_y)+1);
    printf(" ");

    /* ���ư���˵�� */
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);     //����������ɫ
    gotoxy(hOut,85,18);
    printf("ʹ��W,S,A,D�����ƶ�");
    gotoxy(hOut,85,20);
    printf("%c����С��,%c��������",12,30);
    return;
}
void printPos(HANDLE hOut , people** mypeople)      //��������λ��
{
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    gotoxy(hOut,85,10);
    printf("��ǰ����λ��Ϊ��%d,%d",(*mypeople)->x,(*mypeople)->y);
    gotoxy(hOut,85,12);
    printf("��ǰ�������߲���Ϊ:%d",(*mypeople)->step);
    return;
}
void printWin(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
    gotoxy(hOut,85,14);
    printf("���ѻ��ʤ������������˳���Ϸ��");
    return;
}
void gotoxy(HANDLE hOut, int x, int y)  //�ƶ����
{
      COORD pos;
      pos.X = x;             //������
      pos.Y = y;            //������
      SetConsoleCursorPosition(hOut, pos);
      return;
}
bool judgePepBfs(people mypeople , char (*map)[81], int out_y , HANDLE hOut)      //����BFS�㷨�жϵ�ǰ��ͼ�Ƿ��н�
{
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //С���ƶ�����
    int book[31][81];                         //��¼λ��
    memset(book,0,sizeof(book));

    queue<people> myqueue;                          //���ɶ���
    book[mypeople.y][mypeople.x] = 1;
    myqueue.push(mypeople);

    int tempx , tempy;
    //mypeople.print_pos(hOut);     //����

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
                //tempPeople.print_pos(hOut);       //����
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
    /*��ʼ�ж�*/
    if (map[mybox.x+1][mybox.y] == '#' || map[mybox.x+1][mybox.y] == 5)
    {
        return false;
    }
    else if (map[mybox.x-1][mybox.y] == '#' || map[mybox.x-1][mybox.y] == 5)
    {
        return false;
    }
    else if (map[mybox.x][mybox.y+1] == '#' || map[mybox.x][mybox.y+1] == 5)
    {
        return false;
    }
    else if (map[mybox.x][mybox.y-1] == '#' || map[mybox.x][mybox.y-1] == 5)
    {
        return false;
    }

    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //С���ƶ�����
    int book[31][81];                         //��¼λ��
    memset(book,0,sizeof(book));

    queue<box> myqueue;                          //���ɶ���
    book[mybox.y][mybox.x] = 1;
    myqueue.push(mybox);

    int tempx , tempy;
    //mybox.print_pos(hOut);     //����

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
                //tempbox.print_pos(hOut);       //����
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
/*С�˵Ĳ���*/
void people::init_pos()
{
    this->y = rand() % 29 + 1;
    this->x = rand() % 79 + 1;
    this->step = 0;
    return;
}
/*����С��*/
void people::print_pos(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
    gotoxy(hOut,this->x,this->y);
    printf("%c",12);
    return;
}
/*ɾ��С��*/
void people::delete_pos(HANDLE hOut)
{
    gotoxy(hOut,this->x,this->y);
    printf(" ");
    return;
}
/*С�˵��ƶ�*/
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
/* С���������ƶ� */
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
    if (flag)
    {
        this->step++;
    }
    return;
}
/* ���ӵĲ��� */
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
void box::print_pos(HANDLE hOut)     //��������
{
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
    gotoxy(hOut,this->x,this->y);
    printf("%c",30);
    return;
}
void box::init_pos()     //��ʼ������λ��
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