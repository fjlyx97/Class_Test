#include <iostream>
using namespace std;
int main()
{
    int W , N;
    int num[101] = {0};
    int book[101] = {0};
    int money = 0;
    int temp;
    cin >> W >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> num[i];
        book[i] = 0;
    }
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = N ; j >= 1 ; j--)
        {
            if (book[i] == 0 && book[j] == 0)
            {
                temp = num[i] + num[j];
                if (temp <= W)
                {
                    book[i] = 1;
                    book[j] = 1;
                    money += 10;
                }
            }
        }
    }
    for (int i = 1 ; i <= N ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            money += 10;
        }
    }
    cout << money << endl;
    system("pause");
    return 0;
}