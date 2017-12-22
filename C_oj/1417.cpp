#include <iostream>
#include <cstdio>
using namespace std;
char map[4][4];
int main()
{
	int i , j;
	for ( i = 1 ; i <= 3 ; i++)
	{
		for ( j = 1 ; j <= 3 ; j++)
		{
			map[i][j] = getchar();
		}
		getchar();
	}
	for ( i = 1 ; i <= 3 ; i++)
	{
		if (map[i][1] == map[i][2] && map[i][2] == map[i][3])
		{
			if (map[i][1] != '.')
			{
				printf("%c",map[i][1]);
				return 0;
			}
		}
	}
	for ( i = 1 ; i <= 3 ; i++)
	{
		if (map[1][i] == map[2][i] && map[2][i] == map[3][i])
		{		
			if (map[1][i] != '.')
			{
				printf("%c",map[1][i]);
				return 0;
			}
		}
	}
	if (map[1][1] == map[2][2] && map[2][2] == map[3][3])
	{
		if (map[1][1] != '.')
		{
			printf("%c",map[1][1]);
			return 0;
		}
	}
	if (map[1][3] == map[2][2] && map[2][2] == map[3][1])
	{
		if (map[1][3] != '.')
		{
			printf("%c",map[1][3]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}