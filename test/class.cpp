#include <iostream>
using namespace std;
class CPeople
{
private:
    int i;
public:
    CPeople(int ii) : i(ii) {}
    friend int operator- (const CPeople&a , const CPeople& b);
    int operator+ (const CPeople& a)
    {
        return (i+a.i);
    }
};
int operator- (const CPeople& a, const CPeople& b)
{
    return (a.i - b.i);
}
int main()
{
    CPeople a1(12) , a2(12);
    cout << a1+3 << endl;
    cout << 3-a2 << endl;

    system("pause");
    return 0;
}