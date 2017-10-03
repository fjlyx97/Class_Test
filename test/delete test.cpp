#include <iostream>
using namespace std;
class CPeople
{
    int age;
    int height;
public:
    CPeople():age(10),height(180){}
};
int main()
{
    CPeople* a = new CPeople;
    delete a;
    a = NULL;
    system("pause");
    return 0;
}