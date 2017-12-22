#include <iostream>
using namespace std;
int res[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int T;
	int n , m , k;
	int ans;
	int temp_m;
	int flag;
	int i;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> k;
		ans = 0;
		flag = 1;
		for ( i =1 ; i <= n ; i++)
		{
			cin >> res[i];
		}
		for ( i = 1 ; i <= n ; i++)
		{

			temp_m = m;
			if (res[i] == 1) temp_m -= 10;
			if (res[i] == 2) temp_m -= 5;
			if (res[i] == 3) temp_m -= 5;
			if (res[i] == 4) temp_m -= 3;
			if (res[i] == 5) temp_m += 20;
			

			if ( temp_m < 0 )
			{
				ans++;
				m = 100;
			}

			if (res[i] == 1) m -= 10;
			if (res[i] == 2) m -= 5;
			if (res[i] == 3) m -= 5;
			if (res[i] == 4) m -= 3;
			if (res[i] == 5) m += 20;
			if (m > 100)
			{
				m = 100;
			}
			if ( ans > k )
			{
				cout << "Pdddddd is crazy." << endl;
				break;
			}
		}
		if (ans <= k && flag == 1)
		{
			cout << ans << endl;
		}
	}
	return 0;
}