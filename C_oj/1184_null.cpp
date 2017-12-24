#include <iostream>
#include <algorithm>
using namespace std;
int power[1001];
int book[1001][1001] = {0};
int max_book[1001][1001] = {0};
int min_book[1001][1001] = {0};
int max_pow = 0;
void sum(int id , int id1)
{
    int res = 0;
    int max_num = *max_element(power+id,power+id1+1);
    int min_num = *min_element(power+id,power+id1+1);
    cout << "max_book" << " " << max_num << " " << id << " " << id1 << endl;
    cout << "min_book" << " " << min_num << " " << id << " " << id1 << endl;
    cout << endl;
    max_book[id][id1] = max_num;
    min_book[id][id1] = min_num;
    book[id][id1] = (max_num-min_num)*(max_num-min_num);
    return;
}
void judge(int id , int N , int ans)
{
    if (id == N+1)
    {
        if (ans > max_pow)
        {
            max_pow = ans;
        }
        return;
    }
    if (id > N+1)
    {
        return;
    }
    for (int i = 1 ; i <= N ; i++)
    {
        if (id+i > N)
        {
            break;
        }
        if (power[id+i] < max_book[id][id+i-1] && power[id+i] > min_book[id][id+i-1])
        {
            book[id][id+i] = book[id][id+i-1];
        }
        if (book[id][id+i] == 0)
        {
            sum(id,id+i);
        }
        judge(id+i+1,N,ans+book[id][id+i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int N;
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> power[i];
    }
    judge(1,N,0);
    cout << max_pow << endl;
    system("pause");
    return 0;
}