#include <iostream>
using namespace std;
class CPeople
{
public:
    int age;
    int height;
    CPeople( int a , int b ) : age(a) , height(b)
    {

    }
    void show()
    {
        cout << "my age is " << age << '\t' << "my height is " << this->height << endl;
    }
};
int main(int argc,char **agrv)
{
    CPeople a1(10,180);
    a1.show();
    CPeople* a2 = new CPeople(15,190);
    a2->show();
    delete a2;

    system("pause");
    return 0;
}