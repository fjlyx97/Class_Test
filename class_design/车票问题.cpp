#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int cal(int begin, int over); //计算票价的函数
void cal_money_num(int money , int* ticket);
int main()
{
    srand(time(0));
    int loop = rand() % 10 + 5; //随机生成乘客个数
    int ticket[7] = {0}; //1-6元票价
    int begin , over;   //乘客上下车站
    int ans = 0;            //得到票价结果
    cout << "共有" << loop << "位乘客。" << endl;
    for (int i = 1 ; i <= loop ; i++)
    {
        /* 26个车站 */
        begin = rand() % 26 + 1;
        over = begin + rand() % ((26-begin)+1);
        cout << "第" << i << "位乘客在:" << begin << "上车。" << endl;
        cout << "第" << i << "乘客在:" << over << "下车。" << endl;
        cout << "第" << i << "乘客应该支付:" << cal(begin,over) << "元" << endl;
        cal_money_num(cal(begin,over),ticket);  //统计卖出的张数
        ans += cal(begin,over); //获得单程票价
        cout << endl;
    }
    cout << endl;
    for (int j = 1 ; j <= 6 ; j++)
    {
        cout << j << "元售出的张数为:" << ticket[j] << endl;
    }
    cout << "单程售出的总票价为:" << ans << endl;
    system("pause");
    return 0;
}
int cal(int begin , int over)
{
    int ans = 0;
    if (over - begin <= 6)
    {
        ans = 1;
    }
    else
    {
        int temp = (over-begin) - 6;    //获得多出的站数
        if (temp % 4 == 0)
        {
            ans = temp / 4;
        }
        else
        {
            ans = temp / 4 + 1;
        }
        ans += 1;
    }
    return ans;
}
void cal_money_num(int money , int* ticket)
{
    ticket[money] += 1;
}