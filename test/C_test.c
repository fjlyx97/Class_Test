#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char N[52],k,i;
    gets(N);
	for(k=0;;k++)
	{
        if ( N[k] == '\0')
        {
            break;
        }
		if('A'<=N[k] && N[k]<'Z')
        {
            N[k]=N[k]+32;
        }
	}
	for(i=0;i != '\0';i++)
    {
		printf("%c",N[i]);
    }
    system("pause");
    return 0;
}