#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num;
	int i;
	float result = 1.0;
	scanf("%d",&num);
	for (i = 1; i < 100; i++)
	{
		if (i % 2 == 1)
		{
			result -= num / (float)(i+1); 
		}
		else
		{
			result += num / (float)(i+1);
		}
	}
	printf("%.2f",result);

	system("pause");
	return 0;
}