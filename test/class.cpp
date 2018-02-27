/*
solution:
    行的摆放与列的拜访是无关的，所以可以将两个分开。这样就成了两个简单的一维数组问题。
    当初做这到题目时候想过用n皇后的方法来做。但貌似有陷阱，暂时想不起来是什么陷阱了。
    等想起来后在补充吧。

note:
    问题分解

date:
    2016-5-20
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 5000 + 5;

int n, visRow[maxn], visCol[maxn];
int xl[maxn], yl[maxn], xr[maxn], yr[maxn];

void setBoard(int i) {
    for(int x = xl[i]; x <= xr[i]; x++) {
        //cout << x << endl;
        if(!visRow[x]) {
            for(int y = yl[i]; y <= yr[i]; y++) {
                //cout << y << endl;
                if(!visCol[y]) {
                    visCol[y] = 1;  visRow[x] = 1;
                    printf("%d %d\n", x, y);
                    return;
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d", &n) && n) {
        memset(visCol, 0, sizeof(visCol));
        memset(visRow, 0, sizeof(visRow));

        for(int i = 0; i < n; i++)
            scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);

        for(int i = 0; i < n; i++)
            printf("%d %d %d %d\n", xl[i], yl[i], xr[i], yr[i]);

        for(int i = 0; i < n; i++) {    //按照矩阵顺序放置棋子，记录下已经被占领过的行和列
            setBoard(i);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}