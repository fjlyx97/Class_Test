#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,n;
	char a[100][70], b[50]="0.99999999999999999999";
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
		{
			if (a[i][j] == b[j])
			{
				if (j == 22)
				{
					printf("Yes\n");
					break;
				}
				continue;
			}
			else if (a[i][j] > b[j])
			{
				printf("Yes\n");
				break;
			}
			else
			{
				printf("No\n");
				break;
			}
		}
	}
    system("pause");
	return 0;
}
