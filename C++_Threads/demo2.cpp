#include <iostream>
#include <thread>
using namespace std;
class TA
{
public:
    int &m_i;
    TA(int &i) : m_i(i)
    {

    }
    void operator()()
    {
        cout << "m_i1 value is " << m_i << endl;
        cout << "m_i2 value is " << m_i << endl;
        cout << "m_i3 value is " << m_i << endl;
        cout << "m_i4 value is " << m_i << endl;
        cout << "m_i5 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
        cout << "m_i6 value is " << m_i << endl;
    }
};

int main()
{
    auto mylambda = []{
        cout << "线程开始执行了" << endl;
    };
    thread myobj(mylambda);
    myobj.join();
    cout << "I love China!" << endl;

    system("pause");
    return 0;
}