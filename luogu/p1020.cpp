#include <iostream>
#include <cstdio>
using namespace std;
int num[100001] = {0};
int dp[100001] = {0};
int low_dp[100001] = {0};
int main()
{
    int i = 1;
    int max_ans = 0;
    int lowmax_ans = 0;
    while (cin >> num[i])
    {
        i++;
    }
    i--;
    dp[1] = 1;
    low_dp[1] = 1;
    for (int j = 1 ; j <= i ; j++)
    {
        /* first question */
        for (int k = 1 ; k < j ; k++)
        {
            if (num[j] < num[k] && dp[k]+1 > dp[j])
            {
                dp[j] = dp[k]+1;
                if (dp[j] > max_ans)
                {
                    max_ans = dp[j];
                }
            }
            else if (dp[j] == 0)
            {
                dp[j] = 1;
                if (dp[j] > max_ans)
                {
                    max_ans = dp[j];
                }
            }
        }
        /* second question*/
        for (int l = 1 ; l < j ; l++)
        {
            if (num[j] > num[l] && low_dp[l]+1 > low_dp[j])
            {
                low_dp[j] = low_dp[l]+1;
                if (low_dp[j] > lowmax_ans)
                {
                    lowmax_ans = low_dp[j];
                }
            }
            else if (low_dp[j] == 0)
            {
                low_dp[j] = 1;
                if (low_dp[j] > lowmax_ans)
                {
                    lowmax_ans = low_dp[j];
                }
            }
        }
    }
    cout << max_ans << endl << lowmax_ans << endl;
    system("pause");
    return 0;
}