#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>
#include <string.h>  
int main(void)  
{  
    int t,n,m,ans,s;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        m=n%10;  
        if(m==0||m==1||m==5||m==6)  
        {  
            printf("%d\n",m);  
        }  
        else if(m==2)  
        {  
            s=n%4;  
            if(s==0) ans=6;  
            else if(s==1) ans=2;  
            else if(s==2) ans=4;  
            else ans=8;  
            printf("%d\n",ans);  
        }  
        else if(m==3)  
        {  
            s=n%4;  
            if(s==0) ans=1;  
            else if(s==1) ans=3;  
            else if(s==2) ans=9;  
            else ans=7;  
            printf("%d\n",ans);  
        }  
        else if(m==4)  
        {  
            s=n%2;  
            if(s==0) ans=6;  
            else ans=4;  
            printf("%d\n",ans);  
        }  
        else if(m==7)  
        {  
            s=n%4;  
            if(s==0) ans=1;  
            else if(s==1) ans=7;  
            else if(s==2) ans=9;  
            else ans=3;  
            printf("%d\n",ans);  
        }  
        else if(m==8)  
        {  
            s=n%4;  
            if(s==0) ans=6;  
            else if(s==1) ans=8;  
            else if(s==2) ans=4;  
            else ans=2;  
            printf("%d\n",ans);  
        }  
        else  
        {  
            s=n%2;  
            if(s==0) ans=1;  
            else ans=9;  
            printf("%d\n",ans);  
        }  
    }  
    system("pause");
    return 0;
}  