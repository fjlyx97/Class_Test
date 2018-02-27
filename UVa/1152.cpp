//分别枚举两边，然后CD用二分法查找
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int A_B[4001*4001];
int C_D[4001*4001];
int A_B_id = 1;
int C_D_id = 1;
int ans;
void find_ans(int num)
{
    int low = 1;
    int high = C_D_id-1;
    int mid;
    num = - num;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if (num < C_D[mid])
        {
            high = mid-1;
        }
        else if (num > C_D[mid])
        {
            low = mid+1;
        }
        else if (num == C_D[mid])
        {
            for (int i = low ; i <= high ; i++)
            {
                if (num == C_D[i])
                {
                    ans++;
                    if (C_D[i+1] != num)
                    {
                        return;
                    }
                }
            }
        }
    }
    return;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int id;
    int n;
    cin >> id;
    for (int i = 1 ; i <= id ; i++)
    {
        cin >> n;
        ans = 0;
        A_B_id = 1;
        C_D_id = 1;
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> A[j];
            cin >> B[j];
            cin >> C[j];
            cin >> D[j];
        }
        for (int j = 1 ; j <= n ; j++)
        {
            for (int k = 1 ; k <= n ; k++)
            {
                A_B[A_B_id] = A[j]+B[k];
                A_B_id++;
            }
        }
        for (int j = 1 ; j <= n ; j++)
        {
            for (int k = 1 ; k <= n ; k++)
            {
                C_D[C_D_id] = C[j]+D[k];
                C_D_id++;
            }
        }
        sort(C_D+1,C_D+C_D_id);
        for (int j = 1 ; j < A_B_id ; j++)
        {
            find_ans(A_B[j]);
        }
        cout << ans << endl;
        if (i < id)
            cout << endl;
    }

    system("pause");
    return 0;
}