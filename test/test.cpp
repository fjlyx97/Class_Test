#include <iostream>
using namespace std;
class Vector4
{
public:
    Vector4(int a1,int a2 , int a3,int a4)
    {
        v[0] = a1;
        v[1] = a2;
        v[2] = a3;
        v[3] = a4;
    }
    int& operator[](int bi);
private:
    int v[4];
};
int& Vector4::operator[](int bi)
{
    return v[bi]; //[]重载
}
int main()
{
    Vector4 ve(1,2,3,4);
    cout << ve[3];
    system("pause");
    return 0;
}