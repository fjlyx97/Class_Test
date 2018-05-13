#include <iostream>
#include <cstring>
#include <map>
using namespace std;
bool charExist[27] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<char,char> pd;
    char passWord[101] = {0};
    char nonePassword[101] = {0};
    char aimPassword[101] = {0};
    cin >> passWord;
    cin >> nonePassword;
    cin >> aimPassword;
    int len1 = strlen(passWord);
    int len2 = strlen(nonePassword);
    int len3 = strlen(aimPassword);
    for (int i = 0 ; i < len1 ; i++)
    {
        charExist[nonePassword[i]-64] = 1;
        if (pd.count(passWord[i]) == 0 || pd[passWord[i]] == nonePassword[i])
        {
            pd[passWord[i]] = nonePassword[i];
        }
        else
        {
            cout << "Failed" << endl;
            return 0;
        }
    }
    for (int i = 1 ;i <= 26 ; i++)
    {
        if (charExist[i] == 0)
        {
            cout << "Failed" << endl;
            return 0;
        }
    }
    for (int i = 0 ; i < len3 ; i++)
    {
        cout << pd[aimPassword[i]];
    }
    cout << endl;



    system("pause");
    return 0;
}