#include <iostream>
using namespace std;
void fun(int);
int main()
{
    try
    {
        fun(3);
    }
    //catch(int a)
    //{
    //    a = 11;
    //    cout << "renew a value is " << a << endl;
    //}
    catch(...)
    {
        cout << "error" << endl; //如果并不知道抛出的类型，可以用三个点代替。
    }
    system("pause");
    return 0;
}
void fun(int a)
{
    while (a <= 10)
    {
        if (a == 5)
        {
            cout << "This is error" << endl;
            cout << "a is value is : " << a << endl; 
            throw(a);
        }
        else
            cout << a << endl;
        a++;
    }
}