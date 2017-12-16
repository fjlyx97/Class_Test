#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int i;
	int sum = 0;
	char word[101][99];
	scanf("%d",&N);
	for ( i = 0 ; i < N ; i++)
	{
		scanf("%s",word[i]);
	}
	for ( i = 0 ; i < N ; i++)
	{
		if (!strcmp("doubleclick",word[i]))
		{
			printf("666");
			return 0;
		} 
		if (!strcmp("click",word[i]))
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}