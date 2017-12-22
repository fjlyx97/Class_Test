#include <iostream>
using namespace std;
int num[100001];
int book[100001] = {0};
int main()
{
	int n , m;
	int ans;
	int a , b;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> num[i];
		book[i] = book[i-1] + num[i];
	}
	while (m--)
	{
		cin >> a >> b;
		ans = 0;
		ans = book[b] - book[a-1];
		cout << ans << endl;
	}
	return 0;
}