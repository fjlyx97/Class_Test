#include <iostream>
#include <cstring>
using namespace std;
char str[505];
int num1[505];
int num2[505];
int res[505];
int len1 , len2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;

    cin >> str;
    k = 0;
    len1 = strlen(str);
    for ( int j = len1 ; j >= 1 ; j--)
    {
        num1[j] = str[k]-48;
        k++;
    }
    
    cin >> str;
    k = 0;
    len2 = strlen(str);
    for ( int j = len2 ; j >= 1 ; j--)
    {
        num2[j] = str[k]-48;
        k++;
    }
    int carry = 0;
    int temp = 0;
    for ( int i = 1 ; i < 505 ; i++)
    {
        temp = num1[i] + num2[i] + carry;
        res[i] = temp % 10;
        carry = temp / 10;
    }
    int flag = 0;
    for ( int i = 504 ; i >= 1 ; i--)
    {
        if (res[i] != 0)
        {
            flag = 1;
        }
        if (flag)
        {
            cout << res[i];
        }
    }
    if (flag == 0)
    {
        cout << 0;
    }
    cout << endl;

    system("pause");
    return 0;
}