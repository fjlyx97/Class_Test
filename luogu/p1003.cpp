#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a , b, g , k;
    int x , y;
    int id = 1;
    int ans = 0;    
    int num[n][4]; //用数组储存输入的坐标以及宽度
    for (int i = 0 ; i < n ; i++) //循环输入
    {
        cin >> num[i][0] >> num[i][1] >> num[i][2] >> num[i][3];
    }
    cin >> x >> y;
    for ( int i = 0 ; i < n ; i++)
    {
        if (num[i][0] <= x && x <= num[i][0]+num[i][2] && num[i][1] <= y && y <= num[i][1]+num[i][3])
        {
            //判断坐标，如果x,y在矩形内部，则更新覆盖地毯的id
            ans = id;
        }
        id++;
    }
    if (ans == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    system("pause");
    return 0;
}