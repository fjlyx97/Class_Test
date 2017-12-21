#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char str[512];
stack<char> my_stack;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    int len = strlen(str);
    for ( int i = 0 ; str[i] != '@' && i < len; i++)
    {
        if (str[i] == '(' )
        {
            my_stack.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (my_stack.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            if (my_stack.top() == '(')
            {
                my_stack.pop();
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (my_stack.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}