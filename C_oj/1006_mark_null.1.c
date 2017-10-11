#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("%d",1/10);
	int number,i=0,sum=0;
	scanf("%d",&number);
	while( number !=0 )
	{
		printf("%d\n",number);
		sum += number % 10;
		number /= 10;
		i++;
	}
	printf("n=%d;sum=%d",sum,i);
    system("pause");
	return 0;
}