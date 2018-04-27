#include <iostream>
using namespace std;
class book
{
private:
    int qu;
    int price;
    int iIndex;
    static int gInt;
public:
    book()
    {
        iIndex = gInt++;
        qu = iIndex + 1;
        price = qu * 10;
    }
    void print()
    {
        cout << "第" << iIndex + 1 << "个值是" << price << endl;
    }
};
int book::gInt = 0;
int main()
{
    book *p[5];
    for (int i = 0 ; i < 5 ; i++)
    {
        p[i] = new book;
        p[i]->print();
        delete p[i];
    }
    return 0;
}