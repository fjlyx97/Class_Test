#include <iostream>
#include <string>
using namespace std;
int a[100001];
int b[100001];
int c[1000001];
void init(int num[])     //读入数字
{
    string a;
    cin >> a;
    num[0] = a.length();
    for (int i = 1 ; i <= num[0] ; i++)
    {
        num[i] = a[num[0]-i] - '0';
    }
    return;
}
void del_num(int* a , int* b)
{
    for (int i = 1 ; i <= a[0] ; i++)
    {
        if (a[i] < b[i])
        {
            a[i+1] -= 1;
            a[i] += 10;
        }
        c[i] = a[i]-b[i];
    }
    int flag = 0;
    for (int i = a[0] ; i > 1 ; i--)
    {
        if (c[i] != 0 && flag == 0)
        {
            flag = 1;
        }
        if (flag)
        {
            cout << c[i];
        }
    }
    cout << c[1];
    cout << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(a);
    init(b);
    int flag = 1;
    if (a[0] > b[0])
    {
        del_num(a,b);
    }
    else if (a[0] == b[0])
    {
        for (int i = a[0] ; i >= 1 ; i--)
        {
            if (a[i] > b[i])
            {
                flag = 1;
                break;
            }
            else if(a[i] < b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            del_num(a,b);
        }
        else
        {
            cout << '-';
            del_num(b,a);
        }
    }
    else
    {
        cout << '-';
        del_num(b,a);
    }
    system("pause");
    return 0;
}