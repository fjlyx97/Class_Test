#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string,int> m1;
    m1["test"] = 1;
    map<string,int>::iterator it = m1.find("test");
    cout << it->first << endl;
    system("pause");
    return 0;
}