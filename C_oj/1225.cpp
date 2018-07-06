#include <iostream>
#include<stdio.h>  
using namespace std;
int main()  
{  
    long long ret = 0;  
    long long N;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ret = 0;
        scanf("%I64d", &N);  
        while(N)  
        {  
            N >>= 1;
            ret += N;  
        }  
        printf("%I64d\n", ret);  
    }
    system("pause");
    return 0;  
}