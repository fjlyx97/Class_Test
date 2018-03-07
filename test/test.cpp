#include <iostream>
using namespace std;
class CPeople
{
private:
    int age;
public:
    CPeople(int n)
    {
        age = n;
    }
    ~CPeople()
    {
        cout << this->age << endl;
    }
    friend void print(const CPeople& a);
};
void print(const CPeople& a)
{
    cout << a.age << endl;
}
int main()
{
    CPeople xiaoming(10);
    print(xiaoming);
    system("pause");
    return 0;
}