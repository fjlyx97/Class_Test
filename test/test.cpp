#include <iostream>
using namespace std;
class CBase
{
private:
    int age;
public:
    CBase() : age(10) {}
    CBase& operator=(const CBase& c1)
    {
        this->age = c1.age;
        cout << "进入=重载" << endl;
        return *this;
    }
};
int main()
{
    CBase b1;
    CBase b2;
    b2 = b1;
    return 0;
}
