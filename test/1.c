#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n = 1;
	int result = 0;
	int num;
	int i = 0;
	int save_num;
	while (1)
	{
		printf("please input a number:");
		scanf("%d",&n);
		if ( 0 == n)
		{
			break;
		}
		if ( (n * n * n) % 2 == 0)
		{
			num = n * n * n - 1;
		}
		else
		{
			num = n * n * n;
		}
		save_num = num;
		while (result != n * n * n)
		{
			result = 0;
			num = save_num;
			for ( i = 0 ; i < n ; i++)
			{
				result += num;
				num -= 2;
			}
			save_num -= 2;
		}
		printf("result = %d^3 = ",n);
		save_num += 2;
		for (i = 0 ; i < n-1 ; i++)
		{
			printf("%d + ",save_num);
			save_num -= 2;
		}
		printf("%d",save_num);
		printf("\n");
	}
	system("pause");
	return 0;
}