#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

void gotoxy(HANDLE hOut , int x , int y);//�ƶ����
void hello();   //��ʼ����
void printMap(HANDLE hOut,char status);   //���Ƶ�ͼ

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
    /*��ʼ��*/
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    CONSOLE_CURSOR_INFO cci;    //ȡ�����
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);

    hello();//���ƻ�ӭ����
    system("cls");
    /* ��ʼ������ */
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
        printMap(hOut,status);//���Ƶ�ͼ
        getche();   //�ȴ�����
        system("cls");
        printMap(hOut,status);//��ֹ����

        dice* mydice = new dice;    //��ʼ����Ա
        dice* mydice1 = new dice;    //��ʼ����Ա
        mydice->init_num();         //��ʼ������
        mydice1->init_num();         //��ʼ������
        loop_value = 0;             //��������
        while (true)
        {
            printDice(hOut,mydice);
            printDice(hOut,mydice1);
            deleteDice(hOut,mydice);
            deleteDice(hOut,mydice1);


            mydice->y += mydice->y_speed;   //�����ٶ�
            mydice->x += mydice->x_speed;   //����ƽ���ٶ�
            mydice1->y += mydice1->y_speed;   //�����ٶ�
            mydice1->x += mydice1->x_speed;   //����ƽ���ٶ�

            mydice->y_speed += 1;           //�������
            mydice->x_speed += 1;           //�������
            mydice1->y_speed += 1;           //�������
            mydice1->x_speed += 1;           //�������

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
            loop_value++;       //ѭ������
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
/*��������*/
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //������
      pos.Y = y;            //������
      SetConsoleCursorPosition(hOut, pos);
}
void hello() //��ʼ����
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       Ͷ����       *\n");
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
void printMap(HANDLE hOut,char status) //���Ƶ�ͼ
{
    //��20����30
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
    printf("���%c�������Ͷ����",status);
    return;
}

/*���ӹ�����*/
void dice::init_num()   //��ʼ������
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