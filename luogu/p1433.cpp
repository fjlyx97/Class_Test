#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    int x;
    int y;
}mpoint[16];
bool book[16] = {0};
double minDis = 0x3f3f3f3f;
int n;
int startx = 0 , starty = 0;
inline double dis(int x1 , int y1 , int x2 , int y2)
{
    double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return distance;
}
void dfs(int step , double distance)
{
    if (distance > minDis) return;
    if (step == n+1)
    {
        minDis = minDis < distance ? minDis : distance;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (book[i] == 0)
        {
            int tempDis = distance;
            book[i] = 1;
            distance += dis(startx,starty,mpoint[i].x,mpoint[i].y);
            //cout << distance << endl;
            startx = mpoint[i].x;
            starty = mpoint[i].y;
            dfs(step+1,distance);
            distance = tempDis;
            book[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> mpoint[i].x >> mpoint[i].y;
    }
    dfs(1,0);
    printf("%.2lf\n",minDis);

    system("pause");
    return 0;
}