#include <iostream>
using namespace std;
int main()
{
    const int a = 20;
    int& b = const_cast<int&>(a);
    cout << b << endl;
    b = 30;
    cout << b << endl;
    cout << a << endl;
    cout << 10 << endl;
    system("pause");
    return 0;
}