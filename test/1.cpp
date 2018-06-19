#include <iostream>
#include <queue>
using namespace std;
int v[100005], t, a, k;
priority_queue<int> q;
int main() {
    cin >> t;
    while(t--) {
        cin >> a;
        v[a] = 1;
        q.push(a);
    }
    while(1) {
        k = q.top();
        cout << k << endl;
        while(k != 0 && v[k]) k /= 2;
        if(k == 0) break;
        q.pop();
        q.push(k);
        v[k] = 1;
    }
    cout << q.top() << endl;
    return 0;
}
