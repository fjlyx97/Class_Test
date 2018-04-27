#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int map[41][41] = {0};
struct mynut
{
    int x , y;
    int num;
}nut[1681];
bool cmp(struct mynut m1 , struct mynut m2)
{
    if (m1.num > m2.num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int M , N , K;
    int index = 1;
    int ansTime = 0;
    int ans = 0;
    cin >> M >> N >> K;
    for (int i = 1 ; i <= M ; i++)
    {
        for (int j = 1 ; j <= N ; j++)
        {
            cin >> map[i][j];    
            if (map[i][j] != 0)
            {
                nut[index].x = j;
                nut[index].y = i;
                nut[index].num = map[i][j];
                index++;
            }
        }
    }
    sort(nut+1,nut+index,cmp);
    int startx = nut[1].x;
    int starty = 0;
    int startindex = 1;
    int temp;
    while(true)
    {
        temp = abs(nut[startindex].x-startx) + abs(nut[startindex].y-starty) + 1;
        if (ansTime + temp + abs(nut[startindex].y) <= K)
        {
            ansTime += temp;
            ans += nut[startindex].num;
            startx = nut[startindex].x;
            starty = nut[startindex].y;
            startindex++;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}