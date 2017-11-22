#include <stdio.h>
int main(void)
{
	int born = 0;
	int today = 0;
	int i = 0;
	int temp = 0;
	scanf("%d,%d",&born , &today);
	for ( i = born ; i < today ; i++)
	{
		if ( (i % 4 == 0 && i % 100 != 0) || ( i % 4 == 0 && i % 4 == 0) )
		{
			temp += 366 * 108000;
		}
		else
		{
			temp += 365 * 108000;
		}
	}
	printf("%d",temp);
	return 0;
}