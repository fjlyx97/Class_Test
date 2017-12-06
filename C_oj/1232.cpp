#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int num[13];
    int i;
    for (i = 1 ; i < 13 ; i++)
    {
        num[i] = i;
    }
    int ans = 0;
    do
    {
        if (num[1] < num[2] && num[2] < num[3] && num[3] < num[4])
        {
            if (num[5] < num[6] && num[6] < num[7] && num[7] < num[8])
            {
                if (num[9] < num[10] && num[10] < num[11] && num[11] < num[12])
                {
                    if (num[1] < num[5] && num[5] < num[9])
                    {
                        if (num[2] < num[6] && num[6] < num[10])
                        {
                            if (num[3] < num[7] && num[7] < num[11])
                            {
                                if (num[4] < num[8] && num[8] < num[12])
                                {
                                    ans++;
                                    for ( i = 1 ; i <= 12 ; i++)
                                    {
                                        printf("%3d ",num[i]);
                                        if (i % 4 == 0)
                                        {
                                            printf("\n");
                                        }
                                    }
                                    printf("\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(next_permutation(num+1,num+13));
    printf("%d",ans);
    system("pause");
    return 0;
}
