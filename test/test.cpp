#include <iostream>
using namespace std;
class CBase
{
private:
    int age;
public:
    CBase(int a) : age(a) { cout << "Base" << endl;}
    void show()
    {
        cout << this->age << endl;
    }
};
class CDev : virtual public CBase
{
public:
    CDev(int a) : CBase(a) { cout << "CDev" << endl; cout << a << endl;}
};
class CDev1 : virtual public CBase
{
public:
    CDev1(int a) : CBase(a) { cout << "CDev1" << endl; a = 20; cout << a << endl;}
};
class CDev2 : virtual public CDev1 , virtual public CDev
{
public:
    CDev2(int a) : CBase(a) , CDev(a) , CDev1(a) { cout << "CDev2" << endl;}
};
class CDev3 : public CDev1
{
public:
    CDev3(int a) : CBase(a) , CDev1(a) {} 
};
int main()
{
    //CDev2 c2(5);
    //c2.show();
    CDev3 c3(10);
    c3.show();
    system("pause");
    return 0;
}