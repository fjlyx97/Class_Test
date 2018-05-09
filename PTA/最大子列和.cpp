#include <iostream>
using namespace std;
int num[100001] = {0};
#define INF 0x3f3f3f3f
int main()
{
    int K;
    int flag = 0;
    cin >> K;
    for (int i = 1;  i <= K ; i++)
    {
        cin >> num[i];
        if (num[i] >= 0)
        {
            flag = 1;
        }
    }
    int max_ans = -INF;
    int this_num = 0;
    int begin = 1 , over = 1;
    int ans_begin = 1;
    for (int i = 1 ; i <= K ; i++)
    {
        this_num += num[i];
        if (this_num > max_ans)
        {
            max_ans = this_num;
            ans_begin = begin;
            over = i;
        }
        if (this_num < 0)
        {
            begin = i+1;
            this_num = 0;
        }
    }
    if (flag == 0)
    {
        cout << 0 << " " << num[1] << " " << num[K] << endl;
    }
    else
    {
        cout << max_ans << " " << num[ans_begin] << " " << num[over] << endl;
    }
    system("pause");
    return 0;
}