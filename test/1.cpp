#include <iostream>
using namespace std;
class Base{
public:
	void show()
    {
        cout << "Base" << endl;
    }
};
class Dev : public Base{
public:
    void DevShow()
    {
        cout << "Dev" << endl;
    }
};
int main()
{
    Dev d;
    Base* b = &d;
    
	system("pause");
	return 0;
}
