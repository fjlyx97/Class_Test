#include <iostream>
#include <cstring>
using namespace std;
int num[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M;
    int pep_num;
    int id;
    int temp;
    memset(num,-1,sizeof(num));
    cin >> N >> M;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> pep_num;
        cin >> id;
        num[id] = id;
        for (int j = 1 ; j < pep_num ; j++)
        {
            cin >> temp;
            num[temp] = id;
        }
    }
    system("pause");
    return 0;
}