#include <iostream>
#include <string>
using namespace std;
int a[50001] = {0};
int b[50001] = {0};
int c[50001] = {0};
void init(int* num)
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
void add_num(int* a , int* b)
{
    int i;
    for (i = 1 ; i <= a[0] ; i++)
    {
       if (a[i]+b[i]+c[i] >= 10)
       {
           c[i+1] += 1;
           c[i] -= 10;
       } 
       c[i] += a[i]+b[i];
    }
    if (c[i] > 0)
    {
        cout << c[i];   
    }
    for ( --i ; i >= 1 ; i--)
    {
        cout << c[i];
    }
    cout << endl;
}
int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(a);
    init(b);
    if (a[0] >= b[0])
    {
        add_num(a,b);
    }
    else
    {
        add_num(b,a);
    }
    system("pause");
    return 0;
}