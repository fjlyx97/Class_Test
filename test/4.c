#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	int num[10];
	int i = 0;
	int x;
	int index = 0;
	int temp;
	int status;
	scanf("%d",&n);
	for (i = 0 ; i < n ; i++)
	{
		scanf("%d",&num[i]);
	}
	if (num[0] > num[1])
	{
		status = 0;
	}
	else
	{
		status = 1;
	}
	scanf("%d",&x);
	num[n] = x;
	if ( 0 == status)
	{
		for ( i = n ; ; i--)
		{
			if (num[i] > num[i-1])
			{
				temp = num[i];
				num[i] = num[i-1];
				num[i-1] = temp;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for ( i = n ; ; i--)
		{
			if (num[i] < num[i-1])
			{
				temp = num[i];
				num[i] = num[i-1];
				num[i-1] = temp;
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0 ; i <= n ; i++)
	{
		printf("%d ",num[i]);
	}
	system("pause");
	return 0;
}