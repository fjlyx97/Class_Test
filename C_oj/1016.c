#include <stdio.h>
int main(void)
{
	int M , K;
	int money = 0;
	int time = 0;
	scanf("%d %d",&M,&K);
	for (; M > 0; M--)
	{
		money++;
		if (money == K)
		{
			M++;
			money = 0;
		}
		time++;
	}
	printf("%d",time);
	return 0;
}