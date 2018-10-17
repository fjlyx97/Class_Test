#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1000010;
int n,tot,a,f_max=1,f_ans,c[maxn],prime[maxn];
bool flag[maxn];
int init()
{
    int p=0;char c=getchar();
    if(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')
    {
        p=p*10+c-'0';
        c=getchar();
    }
    return p;
}
void prepare()
{
    for(int i=2;i<=maxn;i++)
    if(!flag[i])
    {
        prime[++tot]=i;
        for(int j=i+i;j<=maxn;j+=i)
        flag[j]=1;
    }
}
void work(int x)
{
    for(int i=f_max;i<=tot;i++)
    {
        if(prime[i]>x) return;
        if(x%prime[i]==0)
        {
            f_ans=x;
            f_max=i;
        }
    }
}
int main()
{
    prepare();
    n=init();
    for(int i=1;i<=n;i++)
    {
        a=init();
        work(a);
    }
    cout<<f_ans;
    system("pause");
    return 0;
}