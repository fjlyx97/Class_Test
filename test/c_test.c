#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int N;
	int num[50];
	int i;
	int M;
	int a;
	scanf("%d",&N);
	for (i = 0 ; i < N ; i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&M);
	scanf("%d",&a);
	for (i = 0 ; i < N ; i++)
	{
		if ( i == M-1 )
		{
			printf("%d ",a);
		}
		printf("%d ",num[i]);
	}

	system("pause");
	return 0;
}
