#include "stdio.h"
#include <stdlib.h>
int main()
{
	int m,n,i,b,a;
	int j = 0;
	scanf("%d",&i);
	for(a=1;a<=1000;a++)
	{
		if ( j == i)
		{
			break;
		}
		if((a+3)%5==0&&(a-3)%6==0)
		{
			printf("%d\n",a);
			j++;
		}
	}
	system("pause");
	return 0;
}