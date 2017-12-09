#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int N;
    int book[131];
    memset(book,0,sizeof(book));
    int A , B , C;
    cin >> N;
    while (N--)
    {
        cin >> A >> B >> C;
        for (int i = B ; i < B+C ; i++)
        {
            book[i] += A;
        }
    }
    cout << *max_element(book,book+131);
    system("pause");
    return 0;
}