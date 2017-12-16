#include <iostream>
using namespace std;
int book[1001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int temp;
    int num = 0;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> temp;
        if (book[temp] == 0)
        {
            num++;
        }
        book[temp] += 1;
    }
    cout << num << endl;
    for ( int i = 0 ; i < 1001 ; i++)
    {
        if (book[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    system("pause");
    return 0;
}