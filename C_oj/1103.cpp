#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int* num = new int[N];
    int i;
    for (i = 0 ; i < N ; i++)
    {
        cin >> num[i];
    }
    int result = 0;
    int temp = N;
    while (N != 1)
    {
        sort(num,num+temp);
        result += num[0] + num[1];
        num[0] = num[0] + num[1];
        num[1] = 101;
        N--;
    }
    cout << result;
    delete[] num;
    system("pause");
    return 0;
}