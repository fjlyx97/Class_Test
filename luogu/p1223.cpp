#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct mypeople
{
    int num;
    int index;
}people[1001];
bool cmp(struct mypeople& a1 , struct mypeople& a2)
{
    if (a1.num < a2.num) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++)
    {
        cin >> people[i].num;
        people[i].index = i;
    }
    sort(people+1,people+n+1,cmp);
    double res = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j < i ; j++)
        {
            res += people[j].num;
        }
    }
    for ( int i = 1 ; i <= n ; i++)
    {
        printf("%d ",people[i].index);
    }
    printf("\n");
    printf("%.2f",res/n);

    system("pause");
    return 0;
}