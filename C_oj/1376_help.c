#include <stdio.h>
#include <stdlib.h>
#define m 1001
int main(void)
{
    int i,t,n,k,a[m],sum=0,ave=0,ans,yy,j,suma = 0;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        sum=0;
        yy=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)//输入
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if(sum%k != 0)//判断能否完成
        {
            printf("-1\n");
        }
        else
        {
            ave=sum/k;
            ans=n-1 + k-1;
            for(i=0;i<k-1;i++)//分开需要k-1，合并需要n-1如果原来有板则-2
            {
                yy += ave;//判断分完后的每个挡板

                for(j=0;j<n-1;j++)//是否有原来就有的
                {
                    suma += a[j];
                    if(suma==yy)
                    {
                        ans -= 2;
                    }

                }
                suma=0;//suma归0

            }
            printf("%d\n",ans);
        }

    }
    system("pause");
    return 0;
}
