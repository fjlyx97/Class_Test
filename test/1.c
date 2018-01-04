#include"stdio.h"
#include"string.h"
#include <stdlib.h>
int main()
{
	int x,len,hen,i,j,a1=0,a2,b1=0,b2,b3,t,c,c1,c4=0,c5,c2,r;
	char str1[50];
	char str2[50];
	char a[50],b[50],c3[50],e[50];
	char d[50]={'a','b','c','d','e','f','g','h','i','g','k','l','m','n','o','p','q','i','s','t','u','v','w','x','y','z'};//26个
	printf("********************menu********************");
	printf("\n");
	printf("请输入集合A:     ");
	scanf("%s",str1);
	len=strlen(str1);
	printf("请输入集合B:     ");
	scanf("%s",str2);
	hen=strlen(str2);
	printf("请输入数字选择功能\n");
	printf("实现两组的交运算请按1\n");
	printf("实现两组的并运算请按2\n");
	printf("实现两组的补运算请按3\n");
	printf("实现两组集合的子集关系判断请按4\n");
	printf("实现两组集合的组合运算请按5\n");
	scanf("%d",&x);
    while(1)
    {
        if(x==1)//实现两组的交运算
        {
            for(i=0;i<len;i++)
                for(j=0;j<hen;j++)
                {
                    if(str2[j]==str1[i])
                    {
                        a[a1]=str1[i];
                        a1++;
                        a2=a1;
                    }
                }
        
            for(i=0;i<a2;i++)
            {
                printf("%c",a[i]);
            }
            break;
        }
        if(x==2)//实现两组的并运算
        {
            t=0;
            //for(b1=0;b1<len;b1++)
            //{
            //    b[b1]=str1[b1];
            //}
            for(b1=0;b1<len;b1++)	
            {
                for(b2=0;b2<hen;b2++)
                {
                    if(str2[b2]==str1[b1])
                    {
                        b[t]=str2[b2];
                        t++;
                        b3=t;
                    }
                }
            }
            for(i=0;i<b3;i++)
            {
                printf("%c",b[i]);
            }
            break;
        }
        if(x==3)//实现两组的补运算        26个字母-并集   
        {
            int book[27] = {0};     // 1 - 26 a-z
            for ( c = 0 ; c < len ; c++)
            {
                book[str1[c]-96] = 1;
            }
            for (c1 = 0 ; c1 < hen ; c1++)
            {
                book[str2[c1]-96] = 1;
            }
            for ( i = 1 ; i < 27 ; i++)
            {
                if (book[i] == 0)
                {
                    printf("%c ",i+96);
                }
            }
            break;
            //for(i=97;i<123;i++)
            //{
            //    for(c=0;c<len;c++)
            //    {
            //        for(c1=0;c1<hen;c1++)
            //        {
            //            if(str1[c]!=i&&str2[c2]!=i)
            //            {
            //                c3[c4]=i;
            //                c4++;
            //                c5=c4;
            //            }
            //        }
            //    }
            //}
            //for(i=0;i<c5;i++)
            //{
            //    printf("%c",c3[i]);
            //    break;
            //}
        }
        if(x==4)//实现两组集合的子集关系判断			
        {
            printf("输入1判断集合是否为交集关系");
            scanf("%d",&x);
            printf("\n");
            if(a2!=0)
            {
                printf("两集合是交集关系");
            }
            printf("输入2判断集合是否为并集关系");
            scanf("%d",&x);
            printf("\n");
            if(t!=0)
            {
            
                printf("两集合是并集关系");
            }
        }
        if(x==5)//实现两组集合的组合运算
        {
            printf("输入1求出两集合的交集");
            printf("\n");
            scanf("%d",&x);
            printf("输入2求出两集合的并集");
            scanf("%d",&x);
            for(i=0;i<a2;i++)//a[] b[];
            {
                e[i]=a[i];
            
            }
            for(i=a2;i<a2+b3;i++)
                for(j=0;j<b3;j++)
                {
                    if(b[j]!=e[i])
                    {
                        e[i]=b[j];
                        r=i;
                    }
                }
            for(i=0;i<r;i++)	
                printf("%c",e[i]);
        }
    }
    system("pause");
	return 0;
}
