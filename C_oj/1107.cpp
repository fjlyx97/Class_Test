#include <iostream>
#include <algorithm>
using namespace std;
char passwd[21];
int book[21] = {0};
char ans[21] = {0};
int L , C;
void dfs(int step)
{
    if (step == L+1)
    {
        int vowel = 0;//元音
        int consonant = 0;//辅音
        for ( int i = 1 ; i <= L ; i++)
        {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
            {
                vowel++;
            }
            else
            {
                consonant++;
            }
        }
        if (vowel >= 1 && consonant >= 2)
        {
            cout << ans+1 << endl;
        }
        return;
    }
    for ( int i = 1 ; i <= C ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            ans[step] = passwd[i];
            if (step > 1 && ans[step] < ans[step-1])
            {
                book[i] = 0;
                ans[step] = '\0';
            }
            else
            {
                dfs(step+1);
            }
            book[i] = 0;
            ans[step] = '\0';
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> C;
    for ( int i = 1 ; i <= C ; i++)
    {
        cin >> passwd[i];
    }
    sort(passwd+1,passwd+C+1);
    dfs(1);
    system("pause");
    return 0;
}