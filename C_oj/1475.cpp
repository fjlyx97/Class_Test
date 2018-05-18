#include <iostream>
#include <cstdio>
using namespace std;
char str[10000001] = {0};
int main()
{
    int T;
    cin >> T;
    int n , m;
    int t;
    while(T--)
    {
        scanf("%d %d",&n,&m);
        getchar();
        scanf("%s",str);
        int flag = 1;
        for (int i = 1 ; i <= m ; i++)
        {
            scanf("%d",&t);
            if (str[0] == '0')
            {
                if (t == 3)
                {
                    printf("0\n");
                }
                continue;
            }
            if ( n <= 0)
            {
                if (t == 3)
                    printf("0\n");
                continue;
            }
            if (t == 1)
            {
                str[n++] = '0';
                str[n] = '\0';
            }
            else if (t == 2)
            {
                str[--n] = '\0';
            }
            else
            {
                if (n <= 0)
                {
                    printf("0\n");
                }
                else
                {
                    printf("%s\n",str);
                }
            }
        }
    }
    system("pause");
    return 0;
}