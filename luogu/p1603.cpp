#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char str[1001] = {0};
    char ans[1001] = {0};
    int index = 0;
    gets(str);
    char* pch;
    pch = strtok(str," ");
    while (pch != NULL)
    {
        int len = strlen(pch);
        if (strcmp(pch,"one") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '1';
        }
        if (strcmp(pch,"two") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"three") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"four") == 0)
        {
            ans[index++] = '1';
            ans[index++] = '6';
            
        }
        if (strcmp(pch,"five") == 0)
        {
            
            ans[index++] = '2';
            ans[index++] = '5';
        }
        if (strcmp(pch,"six") == 0)
        {
            ans[index++] = '3';
            ans[index++] = '6';
            
        }
        if (strcmp(pch,"seven") == 0)
        {
            ans[index++] = '4';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"eight") == 0)
        {
            ans[index++] = '6';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"nine") == 0)
        {
            ans[index++] = '1';
            ans[index++] = '8';
            
        }
        if (strcmp(pch,"ten") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '0';
            
        }
        if (strcmp(pch,"eleven") == 0)
        {
            ans[index++] = '1';
            ans[index++] = '2';
            
        }
        if (strcmp(pch,"twelve") == 0)
        {
            ans[index++] = '4';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"thirteen") == 0)
        {
            ans[index++] = '6';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"fourteen") == 0)
        {
            ans[index++] = '6';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"fifteen") == 0)
        {
            ans[index++] = '2';
            ans[index++] = '5';
            
        }
        if (strcmp(pch,"sixteen") == 0)
        {
            ans[index++] = '5';
            ans[index++] = '6';
            
        }
        if (strcmp(pch,"seventeen") == 0)
        {
            ans[index++] = '8';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"eighteen") == 0)
        {
            ans[index++] = '2';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"nineteen") == 0)
        {
            ans[index++] = '1';
            ans[index++] = '6';
            
        }
        if (strcmp(pch,"twenty") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '0';
            
        }
        if (strcmp(pch,"a") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '1';
            
        }
        if (strcmp(pch,"both") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"another") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '9';
            
        }
        if (strcmp(pch,"first") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '1';
            
        }
        if (strcmp(pch,"second") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '4';
            
        }
        if (strcmp(pch,"third") == 0)
        {
            ans[index++] = '0';
            ans[index++] = '9';
            
        }
        pch = strtok(NULL," ");
    }
    ans[index] = '\0';
    int flag = 1;
    for (int i = 0 ; i < index ; i++)
    {
        if (ans[i] == '0')
        {
            continue;
        }
        else
        {
            flag = 0;
            cout << ans+i << endl;
            break;
        }
    }
    if (flag) cout << 0 << endl;



    system("pause");
    return 0;
}