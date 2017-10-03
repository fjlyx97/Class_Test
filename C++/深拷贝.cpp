//#include <iostream>
//using namespace std;
//class CHuman
//{
//public:
//	int *age;
//	int heigh;
//	CHuman()
//	{
//		age = new int[2];
//		heigh = 175;
//
//	}
//	~CHuman() 
//	{
//		delete[] age;
//
//	}
//	CHuman(const CHuman& b)
//	{
//		age = new int[2];
//		this->age[0] = b.age[0];
//		this->age[1] = b.age[1];
//	}
//};
//int main()
//{
//	CHuman xiaoming;
//	xiaoming.age[0] = 15;
//	xiaoming.age[1] = 18;
//	cout << xiaoming.age[0] << '\t' << xiaoming.age[1] << endl;
//	CHuman xiaohong = xiaoming;
//	cout << xiaohong.age[0] << '\t' << xiaohong.age[1] << endl;
//
//	system("pause");
//	return 0;
//}