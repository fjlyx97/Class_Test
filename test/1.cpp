#include <iostream>
using namespace std;
class CBase
{
public:
    void show()
    {
        cout << a << endl;
    }
public:
    int a;
};

int main()  
{  
    CBase obj2;
    const CBase* ptr = new CBase;
    ptr->a = 100;
    system("pause");
    return 0;  
}       