#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int m;
	float result = 1.0;
	int i;
	scanf("%d",&m);
	for (i = 1 ; i < m+1 ; i++)
	{
		result = result + 1.0 / (2*i+1); 
	}
	printf("%.6f",result);
	return 0;
}