#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char str[51];
    cin >> n;
    cin >> str;
    n = n % 26;
    int len = strlen(str);
    for ( int i = 0 ; i < len ; i++)
    {
        int temp = str[i];
        temp += n;
        if (temp > 'z')
        {
            temp -= 26;
        }
        str[i] = temp;
    }
    cout << str << endl;
    system("pause");
    return 0;
}