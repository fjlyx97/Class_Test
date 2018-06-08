#include <iostream>
#include <cstdio>
using namespace std;
void getNum(long long& num)
{
    char c;
    while ( (c=getchar()) > '9' || c < '0' );
    num = c-'0';
    while(c = getchar())
    {
        if (c > '9' || c < '0')
        {
            break;
        }
        num = num*10+c-'0';
    }
}
long long save_num[3001][3001];
int main()
{
    long long T , R;
    getNum(T);
    while(T--)
    {
        getNum(R);
        for (int i = 1 ; i <= R ; i++)
        {
            for (int j = 1 ; j <= i ; j++)
            {
                getNum(save_num[i][j]);
            }
        }
        for (int i = R-1 ; i >= 1 ; i--)
        {
            for (int j = 1 ; j <= i ; j++)
            {
                save_num[i][j] = save_num[i][j]+save_num[i+1][j] > save_num[i][j]+save_num[i+1][j+1] ? save_num[i][j]+save_num[i+1][j] : save_num[i][j]+save_num[i+1][j+1];
            }
        }
        cout << save_num[1][1] << endl;
    }
    system("pause");
    return 0;
}