#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <windows.h>
#define true 1
#define false 0
using namespace std;
void hello() //��ʼ����
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         * �밴�������ʼ��Ϸ *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");
    getche();
}
void tip(char map[][81] , int life , int flag)  //��ʾ����
{
    int i , j , k;
    printf("������һ��1-80֮�������\n");
    printf("�������λ���\n");
    printf("��������ķɻ�\n");
    printf("��ǰʣ����ڵ�����:    ");
    for ( i = 1 ; i <= life ; i++)
    {
        printf("%c   ",3);
    }
    printf("\n");
    for ( i = 0 ; i < 20 ; i++)
    {
        if ( i == 10 && life > 0 && flag == 1)
        {
            printf("                    ��ϲ����ʤ��������\n");
        }
        else if ( i == 10 && life <= 0 && flag == 2)
        {
            printf("                    ���ź���Ϸʧ�ܣ�����\n");
        }
        if ( i == 10 && flag == 1 && life > 0)
        {
            printf("                    ��ϲ��ɹ����У�����\n");
        }
        else if (i == 10 && flag == 2 && life > 0)
        {
            printf("                    ���ź�û�����У�����\n");
        }
        for ( j = 0 ; j < 81 ; j++)
        {
            if (map[i][j] == 6)
            {
                for ( k = 1 ; k < j ; k++)
                {
                    printf(" ");
                }
                printf("%c",map[i][j]);
                printf(" <--������");
            }
            else if (map[i][j] == 15)
            {
                for ( k = 1 ; k < j ; k++)
                {
                    printf(" ");
                }
                printf("%c",map[i][j]);
                printf(" <--��̨������",map[i][j]);
            }
            else if (map[i][j] == '\0')
            {
                continue;
            }
            else
            {
                for ( k = 1 ; k < j ; k++)
                {
                    printf(" ");
                }
                printf("%c",map[i][j]);
            }
        }
        printf("\n");
    }
    if ((life >= 0 && flag == 1 )|| (life <= 0 && flag == 2))
    {
        printf("\n");
        printf("�Ƿ���Ҫ������Ϸ����������Y����������N:");
    }
}
void move_bullet(int bullet_x , char map[][81] , int life , int flag)
{
    int i;
    map[18][bullet_x] = '*';
    for ( i = 17 ; i > 0 ; i--)
    {
        system("cls");
        tip(map,life,flag);
        map[i+1][bullet_x] = '\0';
        map[i][bullet_x] = '*';
        Sleep(100);
    }
    map[i+1][bullet_x] = '\0';
}
int main()
{
    int plane;          //�ɻ���ʼ������
    int battery;        //��̨����
    char map[20][81] = {0};
    int life;
    int flag;
    char status;
    srand(time(0));      //��ʼ�����������

    /*ȡ�����*/
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /*ȡ�����*/

    hello();
    system("cls");       //����
    while (true)
    {
        /* ��ʼ����Ϸ���� */
        plane = 1 + rand() % 80;
        battery = 40;
        memset(map,0,sizeof(map));
        map[0][plane] = 6;
        map[19][battery] = 15;
        life = 5;
        flag = 0;
        /* ��ʼ����Ϸ���� */


        while(true)
        {
            system("cls");
            flag = 0;
            tip(map,life,flag);
            printf("������һ������(1-80):");
            map[19][battery] = '\0';
            while (true)
            {
                scanf("%d",&battery);
                getchar();
                if (battery <= 80 && 0 <= battery)
                {
                    break;
                }
                else
                {
                    printf("������Χ�����������룺");
                }
            }
            map[19][battery] = 15;            //������Ͳ
            move_bullet(battery,map,life,flag);    //�ƶ��ӵ�
            if (battery == plane)
            {
                flag = 1;       //����
            }
            else
            {
                flag = 2;       //û����
            }
            system("cls");
            tip(map,life,flag);
            Sleep(1000);
            life--;
            if (life <= 0 && flag == 2)
            {
                system("cls");
                tip(map,life,flag);
                status = getchar();
                break;
            }
            if ( flag == 1 && life >= 0)
            {
                system("cls");
                tip(map,life,flag);
                status = getchar();
                break;
            }
        }
        if (status == 'Y' || status == 'y')
        {
            system("cls");
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}