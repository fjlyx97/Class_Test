#include <iostream>
using namespace std;
class test
{
public:
    test();
    ~test() {};
private:
    int i;
};
test::test()
{
    i = 25;
    for (int ctr = 0 ; ctr < 10 ; ctr++)
    {
        cout << "Counting at"<< ctr << endl;
    }
}
test anObject;
int main()
{
    return 0;
}
