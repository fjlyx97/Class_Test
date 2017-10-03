#include <iostream>
using namespace std;
class SingleMode
{
private:
    SingleMode()
    {
        cout << "hello world" << endl;
    }
public:
    static int num;
    static SingleMode* valueType()
    {
        if (num == 1)
        {
            num = 0;
            return (new SingleMode);
        }
        else
        {
            return NULL;
        }
    }
    ~SingleMode()
    {
        num = 1;
    }
};
int SingleMode::num = 1;
int main()
{
    SingleMode* ptr = SingleMode::valueType();
    delete ptr;
    SingleMode* ptr1 = SingleMode::valueType();
    delete ptr1;
    system("pause");
    return 0;
}