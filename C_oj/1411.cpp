#include <iostream>
#include <cstring>
using namespace std;
int max(int a , int b)
{
	return a>b?a:b;
}
int save_dis[4];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	int n;
	int m;
	int xs , ys;
	int xi , yi;
	int ans;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0 ; i <  4 ; i++)
		{
			save_dis[i] = -9999999;
		}
		while(n--)
		{
			cin >> xs >> ys;
			save_dis[0] = max(save_dis[0],-xs+ys);
			save_dis[1] = max(save_dis[1],-xs-ys);
			save_dis[2] = max(save_dis[2],xs+ys);
			save_dis[3] = max(save_dis[3],xs-ys);
		}
		cin >> m;
		while(m--)
		{
			cin >> xi >> yi;
			int a , b , c , d;
			a = xi - yi + save_dis[0];
			b = xi + yi + save_dis[1];
			c = -xi - yi + save_dis[2];
			d = -xi + yi + save_dis[3];
			ans = max(a , max(b , max(c , d)));
			cout << ans << endl;
		}
	}
	return 0;
}