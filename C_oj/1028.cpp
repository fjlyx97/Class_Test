#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char save_magic[12][101];
int book[12] = {0};
int flag = 0;
void dfs(int sum , char c)
{
    if (flag)
    {
        return;
    }
    for (int i = 1 ; i < sum ; i++)
    {
        if (save_magic[i][0] == c && book[i] == 0)
        {
            int len = strlen(&save_magic[i][0]);
            book[i] = 1;
            if (save_magic[i][len-1] == 'm')
            {
                flag = 1;
                return;
            }
            dfs(sum,save_magic[i][len-1]);
            book[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i = 1;;
    while ((scanf("%s",save_magic[i])) != EOF)
    {
        if (save_magic[i][0] == '0')
        {
            dfs(i,'b');
            if (flag)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            flag = 0;
            i = 1;
        }
        i++;
    }
    system("pause");
    return 0;
}