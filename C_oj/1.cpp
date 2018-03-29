#include <iostream>
#include <cstdio>
using namespace std;
char ans_map[5][5] = {'1','1','1','1','1',
					  '0','1','1','1','1',
					  '0','0','2','1','1',
					  '0','0','0','0','1',
					  '0','0','0','0','0'};
char map[5][5];
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
int next[8][2] = { {2,1} , {1,2} , {-1,2} , {-2,1} , {-2,-1} , {-1,-2} , {1,-2} , {2,-1} };
void dfs(int step , int tx , int ty)
{
	
	for ( int i = 0 ; i < 8 ; i++)
	{
		int next_tx = tx + next[i][0];
		int next_ty = ty + next[i][1];
		if (next_tx < 5 && next_ty < 5)
		{
			swap(map[tx][ty],map[next_tx][next_ty]);
			if (get_dif(map,ans_map) == 0)
			{
				
			}
		}
	}
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
		for (i = 0 ; i < 5 ; i++)
		{
			cin >> map[i];
			for (j = 0 ; j < 5 ; j++)
			{
				if (map[i][j] == '*')
				{
					map[i][j] = '2';
					tx = i;
					ty = j;
				}
			}	
		}
		
	}
	return 0;
}