#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number,i=0,sum=0;
	scanf("%d",&number);
	if (number == 0)
	{
		printf("n=1;sum=0");
		return 0;
	}
	while( number !=0 )
	{
		sum += number % 10;
		number /= 10;
		i++;
	}
	printf("n=%d;sum=%d",i,sum);
    system("pause");
	return 0;
}