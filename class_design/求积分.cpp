#include <iostream>
using namespace std;
float cal_y(float num); //求解y的值
int main()
{
    float x = 1.0;
    float res = 0;
    while (x <= 2.0)
    {
        res += cal_y(x);
        x += 0.01;
    }
    cout << "最终的结果为:" << res << endl;
    system("pause");
    return 0;
}
float cal_y(float num)
{
    float res = 1 / (num*num+4*num);
    return res;
}