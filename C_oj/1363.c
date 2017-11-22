#include <stdio.h>
int main(void)
{
	int A;
	int num[4];
	int i = 0 , j = 0 , k = 0;
	int temp = 0;
	scanf("%d",&A);
	num[0] = A;
	num[1] = A+1;
	num[2] = A+2;
	num[3] = A+3;
	for (i = 0 ; i < 4 ; i++)
	{
		for ( j = 0; j < 4 ; j++)
		{
			for ( k = 0 ; k < 4 ; k++)
			{
				if ( i != j && i != k && j != k )
				{
					temp = num[i] * 100 + num[j] * 10 + num[k];
					printf("%d ",temp);
				}
			}
		}
		printf("\n");
	}

	return 0;
}