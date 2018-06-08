#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[20] = "12345";
    char* p = s;
    cout << strlen(s) << endl;
    cout << strlen(p) << endl;
    system("pause");
    return 0;
}
