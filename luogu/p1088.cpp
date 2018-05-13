#include <iostream>
#include <algorithm>
using namespace std;
int finger[10001] = {0};
int main()
{
    int N;
    int num;
    int index = 0;
    cin >> N;
    cin >> num;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> finger[i];
    }
    do
    {
        index++;
        if (index == num+1) break;
    }while (next_permutation(finger+1,finger+N+1));
    for (int i = 1 ; i <= N ; i++)
    {
        cout << finger[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}