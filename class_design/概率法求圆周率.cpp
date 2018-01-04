#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
    srand(time(0));
    int n = rand() % 1000000 + 100000;
    int m;
    float x , y;
    float dis;
    for ( int i = 1 ; i <= n ; i++)
    {
        x = (rand() % 1000) / 1001.0;
        y = (rand() % 1000) / 1001.0;
        dis = sqrt(pow((x-0),2) + pow((y-0),2));
        if (dis <= 1)
        {
            m++;
        }
    }
    cout << "随机生成了" << n << "个点" << endl;
    cout << "其中" << m << "个点位于扇形当中" << endl;
    cout << "π的值为" << 4*((float)m/n);
    system("pause");
    return 0;
}
