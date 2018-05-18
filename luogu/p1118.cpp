#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , sum;
    int num[15] = {0};
    int num1[15] = {0};
    cin >> n >> sum;
    for (int i = 1 ; i <= n ; i++)
    {
        num[i] = i;
    }
    int flag;
    do
    {
        memcpy(num1,num,sizeof(num));
        flag = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n-i ; j++)
            {
                if ((num1[j] = num1[j]+num1[j+1]) > sum)
                {
                    flag = 1;       
                    break;
                }
            }
            if (flag) break;
        }
        if (num1[1] == sum && flag == 0)
        {
            for (int i = 1 ; i <= n ; i++)
            {
                cout << num[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }while(next_permutation(num+1,num+n+1));
    system("pause");
    return 0;
}