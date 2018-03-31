#include <iostream>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
char ans_map[5][5] = {'1','1','1','1','1',
					  '0','1','1','1','1',
					  '0','0','2','1','1',
					  '0','0','0','0','1',
					  '0','0','0','0','0'};
char map[5][5] = {0};
int ans;
int get_dif(char (*map)[5] , char (*ans_map)[5])
{
	int dif = 0;
	for (int i = 0 ; i < 5 ; i++)
	{
		for (int j = 0 ; j < 5 ; j++)
		{
			if (map[i][j] != ans_map[i][j])
			{
				dif++;
			}
		}
	}
	return dif;
}
const int next_num[8][2] = { {2,1} , {1,2} , {-1,2} , {-2,1} , {-2,-1} , {-1,-2} , {1,-2} , {2,-1} };

void dfs(int step , int tx , int ty)
{
	int dif = get_dif(map,ans_map);

	if (dif == 0)
	{
		ans = ans < step ? ans : step;
		return;
	}
	if (dif + step > 11)
	{
		return;
	}
	if (step > 10)
	{
		return;
	}

	for (int i = 0 ; i < 8 ; i++)
	{
		int next_tx = tx + next_num[i][0];
		int next_ty = ty + next_num[i][1];
		if (next_tx < 5 && next_ty < 5 && next_ty >= 0 && next_tx >= 0)
		{
			swap(map[next_ty][next_tx] , map[ty][tx]);
			dfs(step+1,next_tx,next_ty);
			swap(map[next_ty][next_tx] , map[ty][tx]);
		}
	}
	return;
}
int main()
{
	int T;
	int i , j;
	int tx , ty;
	cin >> T;
	getchar();
	while(T--)
	{
		ans = INF;
		for (i = 0 ; i < 5 ; i++)
		{
			cin >> map[i];
			for (j = 0 ; j < 5 ; j++)
			{
				if (map[i][j] == '*')
				{
					map[i][j] = '2';
					tx = j;
					ty = i;
				}
			}	
		}
		int dif = get_dif(map,ans_map);
		dfs(0,tx,ty);
		if (ans > 10 || ans < 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << ans << endl;
		}
		getchar();
	}
	system("pause");
	return 0;
}