#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[4];
	int i,j,t,k;
	k=0;
	for(i=0;i<4;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(t=0;t<4;t++)
			{
				if(i!=j&&j!=t&&t!=i)
				{
					if(a[i]+a[j]>a[t]&&a[i]+a[t]>a[j]&&a[j]+a[t]>a[i])
					{
						k++;
					}
				}
			}
			if(k==0)
				printf("NO");
			else
				printf("YES");
	system("pause");
	return 0;
}