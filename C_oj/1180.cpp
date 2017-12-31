#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str[100001] = {0};
struct str
{
    int begin;
    int over;
}mystr[1001];
bool cmp(struct str a1 , struct str a2)
{
    if (a1.begin < a2.begin)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    cin >> str >> n;
    int len = strlen(str);
    char temp_str[101];
    int temp_len;
    int k = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> temp_str;
        if (strstr(str,temp_str) != NULL)
        {
            temp_len = strlen(temp_str);
            mystr[k].begin = strstr(str,temp_str) - str;
            mystr[k].over = mystr[k].begin+temp_len-1;
            k++;
            while (strstr(str+mystr[k-1].begin+1,temp_str) != NULL)
            {
                temp_len = strlen(temp_str);
                mystr[k].begin = strstr(str+mystr[k-1].begin+1,temp_str) - str;
                mystr[k].over = mystr[k].begin+temp_len-1;
                k++;
            }
        }
    }
    sort(mystr+1,mystr+k,cmp);
    int ans = -1;
    int max_ans = ans;
    int begin = 0;
    for ( int i = 1 ; i < k ; i++)
    {
        ans = mystr[i].over - begin;
        if (ans > max_ans)
        {
            max_ans = ans;
        }
        begin = mystr[i].begin+1;
    }
    if (ans != -1)
    {
        ans = len - (mystr[k-1].begin+1);
        max_ans = ans > max_ans ? ans : max_ans;
    }
    else
    {
        max_ans = len;
    }
    cout << max_ans << endl;
    system("pause");
    return 0;
}