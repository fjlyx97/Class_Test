#include <iostream>
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
class people
{
public:
    int x;      //С�˺�����
    int y;      //С��������

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
};

/* ���������� */
class box
{
public:
    /*�������궨��*/
    int x;
    int y;
public:

    /*���Ӳ�������*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    /*��������*/
    void print_pos(HANDLE hOut);
};


void hello();   //��ʼ����
void printMap(HANDLE hOut,char (*map)[81]);
void gotoxy(HANDLE hOut, int x, int y); //�ƶ����

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

    hello();

    while (true)
    {
        system("cls");
        printMap(hOut,map); //���Ƶ�ͼ
        people* mypeople = new people;  //��ʼ��С��
        mypeople->init_pos();   //С�˳�ʼ��λ��

        if (map[mypeople->y][mypeople->x] == 5)
        {
            mypeople->init_pos();   //С�˳�ʼ��λ��
        }
        mypeople->print_pos(hOut);

        printf("123");
    }
}

void hello() //��ʼ����
{
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
    return;
}
void printMap(HANDLE hOut , char (*map)[81])
{
    int i , j;
    system("color A");                  //�����ϰ�����ɫ
    for (i = 1 ; i <= 250 ; i++)        //�����ϰ���
    {
        map[rand()%30+1][rand()%80+1] = 5;
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
void gotoxy(HANDLE hOut, int x, int y)  //�ƶ����
{
      COORD pos;
      pos.X = x;             //������
      pos.Y = y;            //������
      SetConsoleCursorPosition(hOut, pos);
      return;
}

/*С�˵Ĳ���*/
void people::init_pos()
{
    this->y = rand() % 30 + 1;
    this->x = rand() % 80 + 1;
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
/*С�˵��ƶ�*/
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

/* ���ӵĲ��� */
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
void box::print_pos(HANDLE hOut)     //��������
{
    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
    gotoxy(hOut,this->x,this->y);
    printf("%c",12);
    return;
}