#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
	int M,K,i;
	scanf("%d%d",&M,&K);
	for(i=0;M!=0;i++)
	{
		M=M-1;
		if(i%K==0)
			M=M+1;
	}
	printf("%d",i);
	system("pause");
	return 0;
}
