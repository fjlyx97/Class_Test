#include <iostream>
using namespace std;
class people
{
private:
    int age;
public:
    people() : age(10) {};
    void print(int age)
    {
        cout << "Hello people" << age << endl;
    }

};

class A : public people
{
public:
    
};


int main()
{
    people a;
    a.print(10);
    A b;
    b.print(20);
    system("pause");
    return 0;
}