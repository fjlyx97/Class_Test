#include <iostream>
using namespace std;
int book[100001] = {0};
struct save_people
{
    int num;
    int save_num[101];
    int save_book[100001];
}people[1001];
int ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M;
    cin >> N >> M;
    int temp_index;
    for ( int i = 1 ; i <= M ; i++)
    {
        cin >> people[i].num;
        for ( int j = 1 ; j <= people[i].num ; j++)
        {
            cin >> people[i].save_num[j];
            people[i].save_book[people[i].save_num[j]] = 1;
        }
    }
    for ( int i = 1 ; i <= M ; i++)
    {
        if (people[i].save_book[0] == 1)
        {
            ans += people[i].num;
            for ( int j = 1 ; j <= people[i].num ; j++)
            {
                book[people[i].save_num[j]] = 1;
            }
        }
    }
    system("pause");
    return 0;
}