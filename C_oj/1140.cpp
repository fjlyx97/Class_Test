#include <iostream>
#include <cmath>
using namespace std;
int two[10001];
void cal(int num)
{
    int k = 0;
    int temp = 0;
    while (num)
    {
        two[k] = num % 2;
        num /= 2;
        k++;
    }
    //cout << k << endl;    
    if (k % 2 == 0)
    {
        for ( int j = 0 ; j < k/2 ; j++)
        {
            swap(two[j],two[k-j-1]);
        }
    }
    else
    {
        for (int j = 0 ; j < k/2 ; j++)
        {
            swap(two[j],two[k-j-1]);
        }
    }
    for (int j = 0 ; j < k ; j++)
    {
        temp += two[j]*pow(2,(double)j);
    }
    cout << temp << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int num;
    cin >> T;
    while (T--)
    {
        cin >> num;
        cal(num);
    }

    system("pause");
    return 0;
}