#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
int main()
{
    int T;
    double r1 , r2 , x1 , x2 , y1 , y2;
    double dis;
    double ans;
    cin >> T;
    while(T--)
    {
        cin >> r1 >> r2;
        cin >> x1 >> y1 >> x2 >> y2;
        dis = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        if (dis >= r1+r2)
            ans = 0;
        else if (dis <= fabs(r1-r2))
        {
            double r = r1 > r2 ? r2 : r1;
            ans = PI * r * r;
        }
        else
        {
            double a1=acos((r1*r1+dis*dis-r2*r2)/(2.0*r1*dis));  
            double a2=acos((r2*r2+dis*dis-r1*r1)/(2.0*r2*dis)); 
            ans = a1*r1*r1+a2*r2*r2-r1*dis*sin(a1);
        }
        printf("%.6lf\n",ans);
    }
    system("pause");
    return 0;
}