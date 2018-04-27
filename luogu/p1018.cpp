#include <iostream>
using namespace std;
int f[41][7];
int main()
{
    int N , K;
    int num[41];
    cin >> N >> K;
    for (int i = 1 ; i <= N ; i++)
    {
        num[i] = N % 10;
        N /= 10;
    }
    for (int i = 1 ; i <= N ; i++)
    {

    }
    system("pause");
    return 0;
}