#include <iostream>
#include <cstring>
using namespace std;
char coin[1024] = {0};
char ans_coin[1024] = {0};
int icoin[1024] = {0};
int ians_coin[1024] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	int len; 
	cin >> coin >> ans_coin;
	len = strlen(coin);
	for (int i = 0 ; coin[i] != '\0' ; i++)
	{
		if (coin[i] == '*')
		{
			icoin[i] = 0;
		}
		else
		{
			icoin[i] = 1;
		}
	}
	for (int i = 0 ; ans_coin[i] != '\0' ; i++)
	{
		if (ans_coin[i] == '*')
		{
			ians_coin[i] = 0;
		}
		else
		{
			ians_coin[i] = 1;
		}
	}
	for (int i = 0 ; i < len ; i++)
	{
		if (icoin[i] != ians_coin[i])
		{
			ans++;
			icoin[i] = !icoin[i];
			icoin[i+1] = !icoin[i+1];
		}
	}
	cout << ans << endl;

	system("pause");
	return 0;
}