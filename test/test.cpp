#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    try
    {
        if (a == 0)
        {
            throw a;
        }
    }
    catch (exception& e)
    {
        //cout << a << endl;
        cout << "a is error " << endl;
    }
    system("pause");
    return 0;
}