#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream a;
	ofstream b;
	string str;
	a.open("1.txt",ios::in);
	b.open("2.txt",ios::app);
	if (!a)
	{
		cout << "Open a file error." << endl;
	}
	if (!b)
	{
		cout << "Open b file error." << endl;
	}
	b << '\n';
	while (getline(a , str))
	{
		b << str;
	}
	a.close();
	b.close();
	system("pause");
	return 0;
}
