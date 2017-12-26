#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 10000
struct stu
{
    char head,end;
}c[max];//每个单词只需要记录它的首尾即可
int w[max],flag,f;//w数组用来记录是否用过
void dfs(char a)
{
    if(a=='m')//看是否到达目标状态
    {
        flag=1;
        return ;//不可以用break,不是循环就不可以用break跳出
    }
    for(int i=0;i<f;i++)
    {
        if(w[i]==0&&c[i].head==a)
        {
            w[i]=1;//标记
            dfs(c[i].end);
            w[i]=0;//清除标记
        }
    }   
}
int main()
{
    char s[max];
    while(scanf("%s",&s)!=EOF)
    {
        if(!strcmp(s,"0"))
          continue;
        f=0;
        c[f].head =s[0];
        c[f].end =s[strlen(s)-1];
        f++;
        while(scanf("%s",&s),strcmp(s,"0"))//上面的程序是为了以后能够循环输入，若删除之前便只能执行一次
        {
            c[f].head =s[0];
            c[f].end =s[strlen(s)-1];
            f++;    
        }
        flag=0;
        for(int i=0;i<f;i++)
        {
            memset(w,0,sizeof(w));
            if(c[i].head =='b')//从首字母是b的单词开始
            {   
                w[i]=1;
                dfs(c[i].end);//尾
            }
            if(flag)//尽快跳出循环
               break;
        }
        if(flag)//dfs是void型，无返回值，可以自定义一个变量确定是否到达目标状态
          printf("Yes.\n");
        else
          printf("No.\n");
    }
	system("pause");
    return 0;
}