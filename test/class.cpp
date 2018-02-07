#include <iostream>
#include <string>
using namespace std;
class people
{
protected:
    int age;
    string name;
    
public:
    people(int pep_age , string pep_name)
    {
        this->age = pep_age;
        this->name = pep_name;
    }
    virtual void print()
    {
        cout << this->age << endl;
        cout << this->name << endl;
    }
};

class xiaoming : public people
{
public:
    xiaoming(int pep_age , string pep_name):people(pep_age , pep_name)
    {

    }
    void print()
    {
        cout << this->age << endl;
        cout << this->name << endl;
    }
};

int main()
{
    people* mypep = new people(18,"lyx");
    mypep->print();
    xiaoming* myxiaoming = new xiaoming(19,"hel");
    myxiaoming->print();
    system("pause");
    return 0;
}