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
    system("cls");
    printMap(hOut,map); //���Ƶ�ͼ

    system("pause");
    return 0;
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
    for (i = 1 ; i <= 300 ; i++)        //�����ϰ���
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
void gotoxy(HANDLE hOut, int x, int y)  //�ƶ����
{
      COORD pos;
      pos.X = x;             //������
      pos.Y = y;            //������
      SetConsoleCursorPosition(hOut, pos);
      return;
}