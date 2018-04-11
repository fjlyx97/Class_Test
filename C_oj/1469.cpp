#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int num[10];
	int i;
	for (i = 0 ; i < 8 ; i++)
	{
		scanf("%d,",&num[i]);
	}
	scanf("%d",&num[8]);
	scanf("%d",&num[9]);
	sort(num,num+10);
	for (i = 0 ; i < 9 ; i++)
	{
		printf("%d,",num[i]);
	}
	printf("%d",num[9]);
	return 0;
}