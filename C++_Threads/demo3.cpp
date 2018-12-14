#include <iostream>
#include <thread>
#include <string>
using namespace std;
class A
{
public:
    void say()
    {
        cout << "Son thread begin.." << endl;
    }
};
int main()
{
    A myobj;
    thread mytobj(&A::say,myobj);
    mytobj.join();

    system("pause");
    return 0;
}