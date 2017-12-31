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
void hello() //开始界面
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         * 请按任意键开始游戏 *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");
    getche();
}
void tip(char map[][81] , int life , int flag)  //提示界面
{
    int i , j , k;
    printf("请输入一个1-80之间的整数\n");
    printf("最多有五次机会\n");
    printf("射中上面的飞机\n");
    printf("当前剩余的炮弹数量:    ");
    for ( i = 1 ; i <= life ; i++)
    {
        printf("%c   ",3);
    }
    printf("\n");
    for ( i = 0 ; i < 20 ; i++)
    {
        if ( i == 10 && life > 0 && flag == 1)
        {
            printf("                    恭喜你获得胜利！！！\n");
        }
        else if ( i == 10 && life <= 0 && flag == 2)
        {
            printf("                    很遗憾游戏失败！！！\n");
        }
        if ( i == 10 && flag == 1 && life > 0)
        {
            printf("                    恭喜你成功命中！！！\n");
        }
        else if (i == 10 && flag == 2 && life > 0)
        {
            printf("                    很遗憾没有命中！！！\n");
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
                printf(" <--打这里");
            }
            else if (map[i][j] == 15)
            {
                for ( k = 1 ; k < j ; k++)
                {
                    printf(" ");
                }
                printf("%c",map[i][j]);
                printf(" <--炮台在这里",map[i][j]);
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
        printf("是否还想要继续游戏，是请输入Y，否请输入N:");
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
    int plane;          //飞机初始化距离
    int battery;        //炮台距离
    char map[20][81] = {0};
    int life;
    int flag;
    char status;
    srand(time(0));      //初始化随机数种子

    /*取消光标*/
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /*取消光标*/

    hello();
    system("cls");       //清屏
    while (true)
    {
        /* 初始化游戏参数 */
        plane = 1 + rand() % 80;
        battery = 40;
        memset(map,0,sizeof(map));
        map[0][plane] = 6;
        map[19][battery] = 15;
        life = 5;
        flag = 0;
        /* 初始化游戏参数 */


        while(true)
        {
            system("cls");
            flag = 0;
            tip(map,life,flag);
            printf("请输入一个数字(1-80):");
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
                    printf("超出范围，请重新输入：");
                }
            }
            map[19][battery] = 15;            //绘制炮筒
            move_bullet(battery,map,life,flag);    //移动子弹
            if (battery == plane)
            {
                flag = 1;       //命中
            }
            else
            {
                flag = 2;       //没命中
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