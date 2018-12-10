#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.txt","r",stdin);
    int N;
    cin >> N;
    int homeworks[12];
    int times = 0;
    int remainCandy[12] = {0};
    int candyIndex = 0;
    int ans = 0;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> homeworks[i];
    }
    for (int i = 1 ; i <= N ; i++)
    {
        //cout << "Time : " << times << endl;
        //cout << "Ans : " << ans << endl;
        int maxTime = 0;
        for (int j = 1 ; j <= candyIndex ; j++)
        {
            if (maxTime < remainCandy[j])
            {
                maxTime = remainCandy[j];
            }
        }
        if (times + homeworks[i] >= 30)
        {
            times = times + homeworks[i] + 5;
            if (maxTime < homeworks[i]+5)
            {
                ans++;
                times -= 30;
                candyIndex = 0;
                remainCandy[++candyIndex] = maxTime+10-5-homeworks[i];
                continue;
            }
            else
            {
                times -= 30;
                for (int j = 1 ; j <= candyIndex ; j++)
                {
                    remainCandy[j] -= homeworks[i];
                    remainCandy[j] -= 5;
                }
                continue;
            }
        }
        if (maxTime < homeworks[i])
        {
            ans++;
            times += homeworks[i];
            remainCandy[++candyIndex] = 10-homeworks[i];
        }
        else
        {
            times += homeworks[i];
            for (int j = 1 ; j <= candyIndex ; j++)
            {
                remainCandy[j] -= homeworks[i];
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}