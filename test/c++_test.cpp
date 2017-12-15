#include<iostream>
using namespace std;
int main()
{
    int num[3];
    int temp;
    for (int i = 0 ; i < 3 ; i++)
    {
        cin >> num[i];
    }
    for (int i  = 0 ; i < 3-1 ; i++)
    {
        for (int j = 0 ; j < 3-i-1 ; j++)
        {
            if (num[j+1] > num[j])
            {
                temp = num[j+1];
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
    }
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;


    system("pause");
    return 0;
}