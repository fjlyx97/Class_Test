#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    int n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<3)
        {
            cout << "Win" << endl;
        }
        else
        {
            cout << "Lose" << endl;
        }
    
    }
    return 0;
}