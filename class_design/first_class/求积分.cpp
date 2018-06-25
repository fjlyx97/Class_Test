#include <iostream>
using namespace std;
double cal_y(double num); //求解y的值
int main()
{
    double x = 1.0;
    double res = 0;
    while (x <= 2.0)
    {
        res += cal_y(x)*0.0000001;
        x += 0.0000001;
    }
    cout << "最终的结果为:" << res << endl;
    system("pause");
    return 0;
}
double cal_y(double num)
{
    double res = 1 / (num*num+4*num);
    return res;
}