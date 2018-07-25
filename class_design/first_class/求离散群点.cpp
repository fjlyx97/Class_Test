#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
struct point    //离散点
{
    int x;
    int y;
    float dis;
};
void cal_dis(int , int , int , int , struct point*);    //计算距离
int main()
{
    srand(time(0));
    int map[81][81] = {0};//初始化地图   
    int n = rand() % 50 + 1; //初始化点集
    int all_x = 0;
    int all_y = 0;
    int circle_x , circle_y;
    float ave_dis = 0;      //求平均半径
    struct point* mypoint = new point[n]; //动态生成结构体数组
    int i , j;
    for (i = 1 ; i <= n ; i++)
    {
        mypoint[i].x = rand()%81;
        mypoint[i].y = rand()%81;
        all_x += mypoint[i].x;
        all_y += mypoint[i].y;
    }
    circle_x = all_x / n;   //圆心
    circle_y = all_y / n;

    for (i = 1 ; i <= n ; i++)
    {
        cal_dis(circle_x,circle_y,mypoint[i].x,mypoint[i].y,&mypoint[i]);
        ave_dis += mypoint[i].dis;
    }
    ave_dis /= n;
    for (i = 1 ; i <= n ; i++)
    {
       if (mypoint[i].dis < ave_dis) 
       {
           map[mypoint[i].x][mypoint[i].y] = 1;
       }
       else
       {
           map[mypoint[i].x][mypoint[i].y] = 2;
       }
    }
    for (i = 0 ; i < 81 ; i++)
    {
        for (j = 0 ; j < 81 ; j++)
        {
            if (map[i][j] == 1)
            {
                cout << '#';
            }
            else if (map[i][j] == 2)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        } 
        cout << endl;
    }
    system("pause");
    return 0;
}
void cal_dis(int circle_x, int circle_y, int x, int y, struct point* mypoint) //计算点到圆心的距离
{
    float dis = sqrt(pow((circle_x-x),2) + pow((circle_y-y),2));
    mypoint->dis = dis;
    return;
}