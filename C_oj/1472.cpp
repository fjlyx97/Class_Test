#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sum = 0;
bool get(int num)
{
	int flag = 0;
	int i;
	for ( i = 2 ; i < num ; i++)
	{
		if (num % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		return false;
	}
	else
	{
		sum += num;
		return true;
	}
}
int main()
{
	int M , N;
	int i;
	int count = 0;
	cin >> M >> N;
	for(i = M ; i <= N ; i++)
	{
		if (get(i))
		{
			count++;
		}
	}
	cout << count << " " << sum;
	return 0;
}