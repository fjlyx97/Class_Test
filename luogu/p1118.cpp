#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , sum;
    int num[13][13] = {0};
    cin >> n >> sum;
    for (int i = 1 ; i <= n ; i++)
    {
        num[1][i] = i;
    }
    int flag;
    do
    {
        flag = 0;
        for (int i = 2 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n-i+1 ; j++)
            {
                num[i][j] = num[i-1][j]+num[i-1][j+1];
                if (num[i][j] > sum)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag) continue;
        else if (num[n][1] == sum)
        {
            for (int i = 1 ; i <= n ; i++)
            {
                cout << num[1][i] << " ";
            }
            cout << endl;
            return 0;
        }
    }while(next_permutation(*(num+1)+1,*(num+1)+n+1));



    system("pause");
    return 0;
}