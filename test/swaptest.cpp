#include <iostream>
using namespace std;
void swap(int* a,int *b);
int main()
{
    int a = 15 , b = 20;
    swap(a,b);
    cout << a << b << endl;

    system("pause");
    return 0;
}
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}