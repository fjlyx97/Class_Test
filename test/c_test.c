#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,x[100],i,a[6]={100,50,10,5,2,1};
	int j,s;
	s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[j]<=x[i])
			{
				x[i]=x[i]-a[j];
				s++;
				if(x[i]==0)
					break;
				else if(x[i]>0)
					continue;
			}
		}
	}
	printf("%d",s);
	system("pause");
	return 0;
}