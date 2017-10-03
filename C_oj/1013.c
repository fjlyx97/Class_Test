#include <stdio.h>
int main(void)
{
	float input_money;
	float output_money;
	scanf("%f",&input_money);
	if (input_money < 1000)
	{
		output_money = 0.00;
		printf("%.2f",output_money);
	}
	else if (input_money >= 1000 && input_money < 5000)
	{
		output_money = (input_money - 1000) * 0.05;
		printf("%.2f",output_money);
	}
	else if(input_money >= 5000 && input_money < 10000)
	{
		output_money = (input_money - 5000) * 0.1 + 200;
		printf("%.2f",output_money);
	}
	else
	{	
		output_money = (input_money - 10000) * 0.2 + 500 + 200;
		printf("%.2f",output_money);

	}
	return 0;
}