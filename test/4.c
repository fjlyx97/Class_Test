#include "stdio.h"
#include <stdlib.h>
int main(void)
{
    int N;
    int S;
    int arr[100];
    scanf("%d %d",&N,&S);
    int a,b,c;
    c=0;
    for(a=1;a<=N;a++)
    {
        for(b=1;b<=N;b++)
        {

            if(a*b==S&&a+b<=N)
            {
                arr[c]=a+b;
                c++;
            }
        }
    }
    int i,j;
    for(i=0;i<c-1;i++)
    {
        if(arr[0]>arr[i])
        {
            arr[0]=arr[i];
        }
    }
    out:
    printf("%d",(N-arr[0])/2);
	system("pause");
	return 0;
}