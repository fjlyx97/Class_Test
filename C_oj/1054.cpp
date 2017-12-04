#include <iostream>
#include <algorithm>
using namespace std;
void create_primer(int* primer)
{
    int i , j;
    int status = 1;
    for (i = 2 ; i < 30 ; i++)
    {
        status = 1;
        for ( j = 2 ; j < i ; j++)
        {
            if (i % j == 0)
            {
                status = 0;
            }
        }   
        if (status == 1)
        {
            primer[i] = 1;
        }
    }
}
int main()
{  
    int n;
    int primer[30] = {0};
    create_primer(primer);
    cin >> n;
    int num[n+1];
    int i;
    int temp;
    for ( i = 0 ; i < n+1 ; i++)
    {
        num[i] = i;
    }
    int status = 1;
    do
    {
        if (num[1] != 1)
        {
            break;
        }
        status = 1;
        for (i = 1 ; i <= n ; i++)
        {
            if (i != n)
            {
                temp = num[i] + num[i+1];
            }
            else
            {
                temp = num[1] + num[i];
            }
            if (primer[temp] != 1)
            {
                status = 0;
                break;
            }
        }
        if (status == 1)
        {
            for ( i = 1 ; i < n+1 ; i++)
            {
                printf("%d ",num[i]);
            }
            printf("\n");
        }
    }while(next_permutation(num+1,num+n+1));  

    system("pause");
    return 0;
}