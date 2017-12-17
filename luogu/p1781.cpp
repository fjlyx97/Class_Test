#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char num[1024];
    char max_num[1024];
    int len = 0;
    int max_len = 0;
    int index = 0;
    int max_index = 0;
    while (n--)
    {
        index++;
        cin >> num;
        len = strlen(num);
        if (len > max_len)
        {
            strcpy(max_num,num);
            max_len = len;
            max_index = index;
        }
        else if (len == max_len)
        {
            for ( int i = 0 ; i < len ; i++)
            {
                if (num[i] > max_num[i])
                {
                    strcpy(max_num,num);
                    max_len = len;
                    max_index = index;
                    break;
                }
                else if (num[i] == max_num[i])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            continue;
        }
    }
    cout << max_index << endl;
    cout << max_num << endl;
    system("pause");
    return 0;
}