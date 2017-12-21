#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int day,x,n;
	day=0;
	scanf("%d",&n);
	while(n!=0)
	{
		x=(int)(n/2);
		if((n/2.0)>x)
			x=x+1;
		n=x;
		day++;
		printf("%d\n",n);
	}
	printf("%d",day);
    system("pause");
    return 0;
}