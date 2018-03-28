#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
	int ilen;
	T *num;
public:
	Array(int len) : ilen(len)
	{
		num = new T[ilen];
	}
	void input()
	{
		cout << "Please input " << ilen << " numbers:";
		for (int i = 0 ; i < ilen ; i++)
		{
			cin >> num[i];
		}
	}
	void show()
	{
		cout << "Numbers : ";
		for (int i = 0 ; i < ilen ; i++)
		{
			cout << num[i] << " ";
		}
		cout << endl;
	}
	void sort()
	{
		cout << "Sort over." << endl;
		for (int i = 0 ; i < ilen-1 ; i++)
		{
			for (int j = 0 ; j < ilen-i-1 ; j++)
			{
				if (num[j] > num[j+1])
				{
					T t = num[j];
					num[j] = num[j+1];
					num[j+1] = t;
				}
			}
		}
	}
	void revrese()
	{
		cout << "Reverese over" << endl;
		T* begin = num;
		T* end = &num[ilen-1];
		T temp;
		while (begin <= end)
		{
			temp = *begin;
			*begin = *end;
			*end = temp;
			begin++;
			end--;
		}
	}
	T* find_element(T number)
	{
		for (int i = 0 ; i < ilen ; i++)
		{
			if (num[i] == number)
			{
				cout << "Already find element :" << num[i] << endl;
				return &(num[i]);
			}
		}
		cout << "Can't find element" << endl;
		return NULL;
	}
	T sum()
	{
		T ans = 0;
		for (int i = 0 ; i < ilen ; i++)
		{
			ans += num[i];
		}
		return ans;
	}
	~Array()
	{
		delete num;
	}
};
int main()
{
	int num;
	cout << "Please input a number : ";
	cin >> num;
	Array<double> arr(num);
	arr.input();
	arr.show();
	arr.sort();
	arr.show();
	arr.revrese();
	arr.show();
	int search_element;
	cout << "Search number : ";
	cin >> search_element;
	arr.find_element(search_element);
	cout << "Total num : " << arr.sum() << endl;
	system("pause");
	return 0;
}

 