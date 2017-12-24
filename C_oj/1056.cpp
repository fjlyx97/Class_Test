#include <iostream>
using namespace std;
int plate[11] = {0};
void dp(int M,int N)
{
    plate[0] = 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int M , N;
    while (T--)
    {
        cin >> M >> N;
        dp(M,N);
    }

    system("pause");
    return 0;
}