#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T;
    int n , m;
    int frogs = 0,chicken = 0;
    scanf("%d",&T);
    int status = 0;
    while (T--)
    {
        frogs = 0;
        chicken = 0;
        status = 0;

        scanf("%d %d",&n,&m);
        for (frogs = 0 ; frogs <= 100000 ; frogs++)
        {
            for (chicken = 0 ; chicken <= 100000 ; chicken++)
            {
                if (frogs * 4 + chicken * 2 == m && frogs + chicken == n)
                {
                    printf("%d %d\n",frogs,chicken);
                    status = 1;
                    break;
                }
            }
            if (status == 1)
            {
                break;
            }
        }
    }

    system("pause");
    return 0;
}