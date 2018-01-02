#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int t,i,j,max,c,n,d,h;
	char m;
	int b[100]={0};
	char a[1000][100];
	scanf("%d",&t);
	getchar();
	n=1;
	max=0;
	for(i=0;i<t;i++)
	{
		gets(a[i]);
		for(j=0;a[i][j]!='\0';j++)
		{
			m=a[i][j];
			for(c=j+1;a[i][c]!='\0';c++)
			{
				if(a[i][c]==m)
				n++;
			}
			b[j]=n;
		}	
	}
	for(i=0;i<t;i++)
	{
		for(d=0;d<=j;d++)
		{
			if(max<b[d])
			{
				h=d;
			}
		}
		printf("%c",a[i][h]);
	}
	system("pause");
	return 0;
}
