#include <iostream>
using namespace std;
int a[10001];
int b[10001];
void judge()
{
	int N;
	int max = 0;
	int max_index = 1;
	int sum = 0;
	int i;
	cin >> N;
	for (i = 1 ; i <= N ; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (i = 1 ; i <= N ; i++)
	{
		cin >> b[i];
		if (b[i] > max)
		{
			max = b[i];
			max_index = i;
		}
	}
	if ( sum <= b[max_index] )
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int T;
	cin >> T;
	while (T--)
	{
		judge();
	}
	return 0;
}