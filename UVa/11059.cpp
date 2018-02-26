#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int num[19];
    long long res;
    long long max_res = 0;
    int add = 0;
    int id = 0;
    while(cin >> n)
    {
        id++;
        max_res = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> num[i];
        }
        for (int i = 1 ; i <= n ; i++)  //长度
        {
            for (int j = 1 ; j <= n ; j++) //起点
            {
                res = 1;
                add = 0;
                for ( int z = j ; z <= n ; z++) //终点
                {
                    res *= num[z];
                    add++;
                    if (add == i)
                    {
                        if (res > max_res)
                        {
                            max_res = res;
                        }
                        add = 0;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",id,max_res);
    }
    system("pause");
    return 0;
}