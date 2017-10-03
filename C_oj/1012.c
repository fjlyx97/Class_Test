#include <stdio.h>
int main(void)
{
	int time;
	float money_1,money_2;
	scanf("%d",&time);
	money_1 = 0.6 * time;
	money_2 = 0.4 * time + 50;
	if (money_1 > money_2)
	{
		printf("%.2f",money_2);
	}
	else
	{
		printf("%.2f",money_1);
	}


	return 0;
}