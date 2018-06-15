#include <iostream>
#include <algorithm>
using namespace std;
struct medge
{
    int x , y , time;
    friend bool operator< (const medge& m1 , const medge& m2)
    {
        return m1.time < m2.time;
    }
}edge[1005];
int N , M;
int min_ans;
int v[1005];
int get_head(int index)
{
    if (v[index] == index)
    {
        return index;
    }
    else
    {
        v[index] = get_head(v[index]);
        return v[index];
    }
}
void merge(int m , int u)
{
    int t1 , t2;
    t1 = get_head(m);
    t2 = get_head(u);
    if (t1 != t2)
    {
        v[t2] = t1;
        N--;
    }
    return;
}
int main()
{
    cin >> N >> M;
    for (int i = 1 ; i <= N ; i++)
    {
        v[i] = i;
    }
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> edge[i].x >> edge[i].y >> edge[i].time;
    }
    sort(edge+1,edge+M+1);
    for (int i = 1 ; i <= M ; i++)
    {
        merge(edge[i].x,edge[i].y);
        if (N == 1)
        {
            cout << edge[i].time << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    system("pause");
    return 0;
}