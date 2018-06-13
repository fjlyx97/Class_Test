#include <stdio.h> 
#include <stdlib.h>
char *mystrspc(char *string,int n)
{
    int i;
    string = (char*)malloc(sizeof(char)*n);
    char* p = string;
    for (i = 1 ; i <= n ; i++)
    {
        *string++ = ' ';
    }
    *string = '\0';
    return p;
}
int main(void)
{
    char* p;
    int n;
    scanf("%d",&n);
    p = mystrspc(p,n);
    printf("***%s***",p);
	return 0;
}
