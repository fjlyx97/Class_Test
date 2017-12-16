#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[999] = {0};
int main()
{
	int T;
	int n;
	int i , j , k;
	int max = 0;
	int num = 0;
	int flag;
	cin >> T;
	while(T--)
	{
		cin >> n;
		k = 0;
		num = 0;
		for ( i = 1 ; i <= n ; i++)
		{
			flag = 1;
			for ( j = 0 ; j < k ; j++)
			{
				if ( i == a[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				a[k] = i*2;
				k++;
				num++;
			}
		}
		cout << num << endl;
	}
	return 0;
}