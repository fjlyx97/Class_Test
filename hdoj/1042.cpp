#include <iostream>
using namespace std; 
int cal[999999];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int carry;
    int flag = 0;
    int ans;
    while (cin >> N)
    {
        flag = 0;
        carry = 0;
        cal[0] = 1;
        for (int i = 2 ; i <= N ; i++)
        {
            for ( int j = 0 ; j <= flag ; j++)
            {
                ans = cal[j] * i + carry;
                cal[j] = ans % 10;
                carry = ans / 10;
            }
            while (carry)
            {
                flag++;
                cal[flag] = carry % 10;
                carry /= 10;
            }
        }
        for ( int i = flag ; i >= 0 ; i--)
        {
            cout << cal[i];
        }
        cout << endl;
    }

    system("pause");
    return 0;
}