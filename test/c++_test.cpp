#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int num[N];
    for (int i = 0 ; i < N ; i++)
    {
        cin >> num[i];
    }
    sort(num,num+N,greater<int>());
    priority_queue<int,vector<int>,less<int> > drag;
    int temp , temp1;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> temp;
        drag.push(temp);
    }
    int result = 0;
    while (drag.size() != 1)
    {
        temp = drag.top();
        drag.pop();
        temp1 = drag.top();
        drag.pop();
        result += temp+temp1;
        drag.push(temp+temp1);
    }
    cout << result << endl;
    system("pause");
    return 0;
}