#include <iostream>
using namespace std;
int main()
{
    int N;
    int i;
    int temp = 0;
    int up_num , down_num;
    cin >> N;   
    for (i = 1 ; temp < N ; i++)
    {
        temp += i;
    }
    i--;
    if (i % 2 == 0)
    {
        down_num = (temp-N)+1;
        up_num = i - (temp-N);
    }
    else
    {
        down_num = i-(temp-N);
        up_num = 1+(temp-N);
    }
    cout << up_num << '/' << down_num;
    system("pause");
    return 0;
}