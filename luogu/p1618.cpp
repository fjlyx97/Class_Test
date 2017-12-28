#include <iostream>
using namespace std;
int book[11] = {0};
int num[11] = {0};
int a, b, c;
int flag = 0;
void dfs(int step)
{
    if (step == 5)
    {
        if (num[4] < num[1])
        {
            return;
        }
    }
    else if (step == 8)
    {
        if (num[4] < num[1] || num[7] < num[4] || num[7] < num[1])
        {
            return;
        }
    }
    if (step == 10)
    {
        float num1 = num[1]*100 + num[2] * 10 + num[3];
        float num2 = num[4]*100 + num[5] * 10 + num[6];
        float num3 = num[7]*100 + num[8] * 10 + num[9];
        if (num1/a*b == num2 && num1/a*c == num3 && num2/b*c == num3)
        {
            flag = 1;
            cout << num1 << " " << num2 << " " << num3 << endl;
        }
        return;
    }
    for (int i = 1 ; i <= 9 ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            num[step] = i;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    dfs(1);
    if (flag == 0)
    {
        cout << "No!!!" << endl;
    }
    system("pause");
    return 0;
}