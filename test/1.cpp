#include <iostream>
using namespace std;
void fun(int *pInt[2])
{
	int* t = pInt[0];
	pInt[0] = pInt[1];
	pInt[1] = t;
}
int main()
{
	int a = 10;
	int b = 20;
	int* pInt[2] = {&a,&b};
	fun(pInt);
	cout << *pInt[0] << " " << *pInt[1];

	system("pause");
	return 0;
}
