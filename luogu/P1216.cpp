#include <iostream>
using namespace std;
int num[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int ans = 0;
	int max_num;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			cin >> num[i][j];
		}
	}
	for (int i = n ; i > 1 ; i--)
	{
		for (int j = 1 ; j < i ; j++)
		{
			max_num = num[i][j] > num[i][j+1] ? num[i][j] : num[i][j+1];
			num[i-1][j] += max_num;
		}
	}
	cout << num[1][1] << endl;
	return 0;
}