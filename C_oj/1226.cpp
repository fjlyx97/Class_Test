#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void judge(int x , int y , int m , int M , int L)
{
	int time = 0;
	int attack = 4;
	if (x >= y)
	{
		while (L > 0)
		{
			L -= x;
			time += 1;
		}
	}
	while ( L > 0)
	{
		if (attack % 4 == 0 && M >= m)
		{
			L -= y;
			M -= m;
			attack = 0;
		}
		else
		{
			attack += 1;
			L -= x;
		}
		time += 1;
	}
	cout << time << endl;
}
int main()
{
	int x , y , m , M , L;
	int time;
	while (cin >> x >> y >> m >> M >> L)
	{
		judge(x,y,m,M,L);
	}
	return 0;
}