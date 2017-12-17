#include <iostream>
using namespace std;
struct people
{
    int k;
    int s;
}mypeople[5001];
void quick_sort(int left , int right)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int base_num = mypeople[left].s;
    while ( i < j)
    {
        while ( j > i)
        {
            if (mypeople[j].s > base_num)
            {
                break;
            }
            j--;
        }
        while ( i < j )
        {
            if (mypeople[i].s < base_num)
            {
                break;
            }
            i++;
        }
        swap(mypeople[i],mypeople[j]);
    }
    swap(mypeople[left],mypeople[i]);
    quick_sort(left,i-1);
    quick_sort(i+1,right);
    return;
}
void quick_id_sort(int left , int right)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int base_num = mypeople[left].k;
    while ( i < j)
    {
        while ( j > i)
        {
            if (mypeople[j].k < base_num)
            {
                break;
            }
            j--;
        }
        while ( i < j )
        {
            if (mypeople[i].k > base_num)
            {
                break;
            }
            i++;
        }
        swap(mypeople[i],mypeople[j]);
    }
    swap(mypeople[left],mypeople[i]);
    quick_id_sort(left,i-1);
    quick_id_sort(i+1,right);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> mypeople[i].k >> mypeople[i].s;
    }
    quick_sort(0,n-1);
    int l;
    int flag = 0;
    for ( int i = 0 ; i < n ; i++)
    {
        flag = 0;
        for ( l = i+1 ; l < n ; l++)
        {
            if (mypeople[i].s == mypeople[l].s)
            {
                flag++;
                continue;
            }
            break;
        }
        if (flag != 0)
        {
            quick_id_sort(i,l-1);
        }
    }
    int num = m*1.5;
    int res = mypeople[num-1].s;
    int ans = num;
    for ( int i = num ; ; i++)
    {
        if (mypeople[i].s == res)
        {
            ans++;
            continue;
        }
        break;
    }
    cout << res << " " << ans << endl;
    for (int i = 0 ; i < ans ; i++)
    {
        cout << mypeople[i].k << " " << mypeople[i].s << endl;
    }
    system("pause");
    return 0;
}