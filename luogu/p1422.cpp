#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    float res = 0;
    cin >> num;
    if (num <= 150)
    {
        res = num*0.4463;
    }
    else if (151 <= num && num <= 400)
    {
        res = 150*0.4463+(num-150)*0.4663;
    }
    else if (401 <= num)
    {
        res = 150*0.4463+(400-150)*0.4663+(num-400)*0.5663;
    }
    printf("%.1f",res);

    system("pause");
    return 0;
}