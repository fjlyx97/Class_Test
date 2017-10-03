#include <iostream>
using namespace std;
class CHuman
{
public:
	int age;
	int height;
	CHuman()
	{
		age = 15;
		height = 150;
	}

};
int operator - (const CHuman & st)
{
	return (-st.age);
}
int operator - (int num1 , const CHuman & st)
{
	return (num1 - st.age);
}
int main()
{
	CHuman st1;
	cout << -st1 << endl;
	cout << 16-st1 << endl;

	system("pause");
	return 0;
}