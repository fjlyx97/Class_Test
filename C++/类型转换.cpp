#include <iostream>
using namespace std;
class CA{
    int A;
};
class CB:public CA{
    int B;
};
int main()
{
    CA* p1;
    CB* p2;
    //旧式类型转换
    (CA*)p2;
    //新式类型转换
    static_cast<CA*>(p2); //两者需要有关系，更有安全性。
    delete p1;
    delete p2;

    system("pause");
    return 0;
}