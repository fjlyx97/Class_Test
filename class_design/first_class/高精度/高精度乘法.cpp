#include <iostream>
#include <string>
using namespace std;
int a[20001] = {0};
int b[20001] = {0};
int c[200001] = {0};
void init_num(int* num)
{
    string a;
    cin >> a;
    num[0] = a.length();
    for ( int i = 1 ; i <= num[0] ; i++)
    {
        num[i] = a[num[0]-i]-'0';
    }
    return;
}
void mul(int* a , int* b)
{
    int i , j;
    for (i = 1 ; i <= a[0] ; i++)
    {
        for (j = 1 ; j <= b[0] ; j++)
        {
            c[i+j-1] += a[i] * b[j];
        }
    }
    for ( int k = 1 ; k <= i+j-1 ; k++)
    {
        if (c[k] >= 10)
        {
            c[k+1] += c[k] / 10;
            c[k] %= 10;
        }
    }
    int flag = 0;
    for (int k = 20000 ; k > 1 ; k--)
    {
        if (c[k] != 0 && flag == 0)
        {
            flag = 1;
        }
        if (flag)
        {
            cout << c[k];
        }
    }
    cout << c[1];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_num(a);
    init_num(b);
    if (a[0] >= b[0])
    {
        mul(a,b);
    }
    else
    {
        mul(b,a);
    }
    system("pause");
    return 0;
}