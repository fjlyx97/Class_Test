#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string,int> m;
    m["name"] = 30;
    m["test"] = 30;
    map<string,int>::iterator it;
    for (it = m.begin() ; it != m.end() ; it++)
    {
        cout << it->first << endl;
    }

    system("pause");
    return 0;
}