#include <iostream>
using namespace std;
#define max( c, d) c>d? c:d
struct stu
{
    int age;
    int height;
};
template<typename T>
void fun(T a)
{
    cout << a << endl;
}
template<> void fun<stu>(stu st) //函数模板具体化
{
    cout << st.age << '\t' << st.height << endl;
}
int main()
{
    //fun(10);
    //fun("hello");
    //fun(true);
    stu nu = { 18 , 180};
    fun(nu);

    system("pause");
    return 0;
}