#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct fruit1
{
    int ki;
    int wi;
}fruit[100005];
int saveFruit[11][100005];
int index[11] = {0};
int l , r;
int ml , mr ;
int mid;
int ansl , ansr;
int num = 0;
__int64 w[100005] = {0};
bool cmp(const fruit1& f1 ,const fruit1& f2)
{
    return f1.wi < f2.wi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char *s = "\ta\018bc";
    for ( ; *s!='\0' ; s++) printf("%c*\n",*s);
    int T;
    int n , m , q;
    cin >> T;
    fruit[0].wi = fruit[0].ki = 0;
    int o = 0;
    while (T--)
    {
        //if (++o > 100) return 0;
        memset(fruit,0,sizeof(fruit));
        memset(index,0,sizeof(index));
        memset(saveFruit,0,sizeof(saveFruit));
        memset(fruit,0,sizeof(fruit));
        cin >> n >> m >> q;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> fruit[i].ki >> fruit[i].wi;
        }
        sort(fruit+1,fruit+n+1,cmp);
        for (int i = 1; i <= n ; i++)
        {
            w[i] = fruit[i].wi;
            w[i] += w[i-1];
            saveFruit[fruit[i].ki][index[fruit[i].ki]++] = fruit[i].wi;
        }
        w[n+1] = w[n];
        for (int i = 1 ; i <= q ; i++)
        {
            l = 0;
            num = 0;
            r = n+1;
            cin >> ml >> mr; 
            while (l <= r)
            {
                mid = (l+r)/2;
                if (fruit[mid].wi > mr)
                {
                    r = mid - 1;
                }
                else if (fruit[mid].wi < mr)
                {
                    l = mid + 1;
                }
                else
                {
                    l = r = mid+1;
                }
            }
            ansr = r;
            l = 0;
            r = n+1;
            while (l <= r)
            {
                mid = (l+r)/2;
                if (fruit[mid].wi < ml)
                {
                    l = mid+1;
                }
                else if (fruit[mid].wi >= ml)
                {
                    r = mid-1;
                }
                else
                {
                    l = r = mid-1;
                }
            }
            ansl = l;
            if (ansl < ansr)
            {
                /*开始二分搜索*/
                int temp_index;
                for (int t = 1 ; t <= 10 ; t++)
                {
                    l = 0 ; r = index[t];
                    while (l <= r)
                    {
                        mid = (l+r)/2;
                        if (saveFruit[t][mid] >= ml)
                        {
                            r = mid-1;
                        }
                        else
                        {
                            l = mid+1;
                        }
                    }
                    if (saveFruit[t][l] >= ml && saveFruit[t][l] <= mr)
                    {
                        num++;
                    }
                }
                
                /*统计总个数*/
                __int64 total_widget = w[ansr]-w[ansl-1];
                printf("ans::%d %lld\n",num,total_widget);
            }
            else
            {
                printf("ans::0 0\n");                
            }
        }
    }
    system("pause");
    return 0;
}