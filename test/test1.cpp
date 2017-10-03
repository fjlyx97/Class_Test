#include <iostream>
using namespace std;
void hello();
int main()
{
    //cout << ary[0][0] << '\t' << ary[0][1] << endl;
    //cout << ary[1][0] << '\t' << ary[1][1] << endl;
    void (*p)() = hello;
    p();
    void (*p1)() = &hello;
    p1();
    cout << &hello << endl;
    system("pause");
    return 0;
}
void hello()
{
    cout << "hello" << endl;
}