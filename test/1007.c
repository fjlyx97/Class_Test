#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int i,x,k;
    float m,sum,result;
    scanf("%d",&x);
    sum=0.0;
    m=2.0;
    for(i=2;i<=100;i++)
    {
        k=pow(-1.0,i+1);
        result=result+k/m;
        m+=1;
    }
    result=x*result;
    sum=1.0+result;
    printf("%.2f",sum);
    system("pause");
    return 0;
}