#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int num[10];
    float res1 , res2;
    int flag;
    while (cin >> n)
    {
        flag = 0;
        if (n == 0)
        {
            break;
        }
        for (int i = 0 ; i < 10 ; i++)
        {
            num[i] = i;
        }
        do
        {
            res1 = num[0]*10000+num[1]*1000+num[2]*100+num[3]*10+num[4];
            res2 = num[5]*10000+num[6]*1000+num[7]*100+num[8]*10+num[9];
            if (res1 / res2 == n)
            {
                flag = 1;
                printf("%d%d%d%d%d / %d%d%d%d%d = %d\n",num[0],num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9],n);
            }
        }while(next_permutation(num,num+10));
        if (!flag)
        {
            printf("There are no solutions for %d.\n",n);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}