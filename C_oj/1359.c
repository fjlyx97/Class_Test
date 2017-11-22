#include <stdio.h>
int main(void)
{
	int x;
	float y = 0;
	scanf("%d",&x);
	if ( x < 0 )
	{
		y = 0;
	}
	else if ( 0 <= x && x <= 15 )
	{
		y = 4.0 * x / 3;
	}
	else
	{
		y = 2.5 * x - 10.5;
	}
	printf("%.2f",y);

	return 0;
}