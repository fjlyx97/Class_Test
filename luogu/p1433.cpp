#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    double x;
	double y;
}mpoint[16];
bool book[16] = {0};
double minDis = 0x3f3f3f3f;
int n;
double startx = 0 , starty = 0;
inline double dis(double x1 , double y1 , double x2 , double y2)
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
		//cout << "Call " << distance << endl;
		return;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		if (book[i] == 0)
		{
			double tempstartx = startx;
			double tempstarty = starty;
			double tempdistance = distance;
			book[i] = 1;
			distance += dis(startx,starty,mpoint[i].x,mpoint[i].y);
			startx = mpoint[i].x;
			starty = mpoint[i].y;
			dfs(step+1,distance);
			book[i] = 0;
			distance = tempdistance;
			startx = tempstartx;
			starty = tempstarty;
		}
	}
	return;
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
    return 0;
}