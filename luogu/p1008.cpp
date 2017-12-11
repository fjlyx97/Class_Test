#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int book[10] = {0};
    int num , num1 , num2;
    int temp , flag = 1;
    for ( int i = 1 ; i < 4 ; i++)
    {
        for (int j = 1 ; j < 10 ; j++)
        {
            for ( int k = 1 ; k < 10 ; k++)
            {
                flag = 1;
                memset(book,0,sizeof(book));
                num = i * 100 + j * 10 + k;
                num1 = num * 2;
                num2 = num * 3;
                if (num1 > 999 || num2 > 999)
                {
                    return 0;
                }
                book[i] = 1;
                book[j] = 1;
                book[k] = 1;
                int temp1 = num1;
                while (num1)
                {
                    temp = num1 % 10;
                    book[temp] = 1;
                    num1 /= 10;
                }
                int temp2 = num2;
                while (num2)
                {
                    temp = num2 % 10;
                    book[temp] = 1;
                    num2 /= 10;
                }
                for (int k = 1 ; k < 10 ; k++)
                {
                    if (book[k] != 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    cout << num << " " << temp1 << " " << temp2 << endl;
                }
            }
        }
    }
    return 0;
}