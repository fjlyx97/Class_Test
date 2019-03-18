#include <iostream>
using namespace std;
#define INF 0X3F3F3F3F
int main()
{
    int MGragh[9][9] = {
        {0 , 10 , INF , INF , INF , 11 , INF , INF , INF},
        {10 , 0 , 18 , INF , INF , INF , 16 , INF , 12},
        {INF , INF , 0 , 22 , INF , INF , INF , INF , 8},
        {INF , INF , 22 , 0 , 20 , INF , INF , 16 , 21},
        {INF , INF , INF , 20 , 0 , 26 , INF , 7 , INF},
        {11 , INF , INF , INF , 26 , 0 , 17 , INF , INF},
        {INF , 16 , INF , INF , INF , 17 , 0 , 19 , INF},
        {INF , INF , INF , 16 , 7 , INF , 19 , 0 , INF},
        {INF , 12 , 8 , 21 , INF , INF , INF , INF , 0}
    };
    int weight[9];      //保存权值
    int index[9];       //保存下标
    int minNum = INF;
    for (int i = 0 ; i < 9 ; i++)
    {
        weight[i] = MGragh[0][i];
        index[i] = 0;
    }
    for (int i = 1 ; i < 9 ; i++)
    {
        int j , k;
        minNum = INF;
        for (j = 0 ; j < 9 ; j++)
        {
            if (weight[j] != 0 && weight[j] < minNum)
            {
                minNum = weight[j];
                k = j;
            }
        }
        cout << index[k] << "->" << k << endl;
        for (auto temp : weight)
        {
            cout << temp << " ";
        }
        cout << endl;

        weight[k] = 0;
        for (j = 0 ; j < 9 ; j++)
        {
            if (weight[j] != 0 && MGragh[k][j] < weight[j])
            {
                weight[j] = MGragh[k][j];
                index[j] = k;
            }
        }
    }

    system("pause");
    return 0;
}