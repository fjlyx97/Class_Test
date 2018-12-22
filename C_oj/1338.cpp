#include <iostream>
#include <cstring>
using namespace std;
struct my_stack
{
    char str[10];
}mstack[20005];
int main()
{
    int N;
    int stackId = 0;
    char temp_str[10];
    int maxLen = 0;
    int len = 0;
    int flag = 0;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> temp_str;
        if (strcmp(temp_str,"if") == 0)
        {
            strcpy(mstack[++stackId].str,"if");
            len = 0;
        }
        else
        {
            if (stackId == 0)
            {
                flag = 1;
            }
            else
            {
                if (strcmp(mstack[stackId].str,"if") == 0)
                {
                    stackId--;
                    len++;
                    if (len > maxLen)
                    {
                        maxLen = len;
                    }
                }
                else
                {
                    flag = 1;
                }
            }
        }
    }
    if (N % 2 == 1 || stackId != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (flag == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << maxLen-1 << endl;
    system("pause");
    return 0;
}