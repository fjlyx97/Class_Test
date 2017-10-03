#include <iostream>
using namespace std;

int main()
{
    float num1,num2;
    char c;
    cin >> num1 >> c >> num2;
    switch(c)
    {
    case '+':
        cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
        break;
    default:
        break;
    }

    system("pause");
    return 0;
}