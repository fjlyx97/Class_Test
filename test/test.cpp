#include <iostream>
using namespace std;
class CPeople
{
public:
    int age;
    int height;
    CPeople()
    {
        age = 15;
        height = 180;
    }
    void show()
    {
        cout << "my age is " << age << endl;
        cout << "my height is " << height << endl;
    }
};
int main()
{
    CPeople stu;
    stu.show();
    cout << "my first helloworld is successful" << endl;
    int a(10);
    cout << a << endl;


    system("pause");
    return 0;
}
