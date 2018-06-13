#include <iostream>
#include <queue>
using namespace std;
struct sword{
    int ci , di; //砍ci 加di
}msword[15];
struct monitorHead{
    int N;
    int t;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M , L;
    int min_ans = 0x3f3f3f3f;
    int book[1003] = {0};
    queue<monitorHead> mHead;
    cin >> N >> M >> L; //N个头 M个骑士 L最大头数
    /*初始化队列*/
    monitorHead m1 = {N,0};
    mHead.push(m1);

    for (int i = 1 ; i <= M ; i++)
    {
        cin >> msword[i].ci >> msword[i].di;
    }
    while(!mHead.empty())
    {
        //cout << mHead.front().N << " " << mHead.front().t << endl;
        for (int i = 1 ; i <= M ; i++)
        {
            if (msword[i].ci > mHead.front().N)
            {
                continue;
            } 
            else 
            {
                int temp_n = mHead.front().N - msword[i].ci;
                //cout << temp_n << endl;
                if (temp_n == 0)
                {
                    //monitorHead t = {0,mHead.front().t+1};
                    if (mHead.front().t+1 < min_ans) 
                    {
                        min_ans = mHead.front().t+1;
                        break;
                    }
                } 
                else 
                {
                    int heads = mHead.front().N - msword[i].ci + msword[i].di;
                    if (heads > L)
                        heads = L;
                    monitorHead t = {heads,mHead.front().t+1};
                    if (book[t.N] == 0)
                    {
                        mHead.push(t);
                        book[t.N] = 1;
                    }
                }
            }
        }
        //cout << ++index << endl;
        mHead.pop();
    }
    if (min_ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << min_ans << endl;
    system("pause");
    return 0;
}