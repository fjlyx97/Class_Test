#include <iostream>
#include <cstdio>
long long book[101][101][101] = {0};
using namespace std;
long long w(long long a , long long b , long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        if (book[20][20][20] == 0)
        {
            long long temp = w(20,20,20);
            book[20][20][20] = temp;
        }
        return book[20][20][20];
    }
    if (a < b && b < c )
    {
        long long j , k , l;
        if (book[a][b][c-1] == 0)
        {
            j = w(a,b,c-1);
            book[a][b][c-1] = j;
        }
        if (book[a][b-1][c-1] == 0)
        {
            k = w(a,b-1,c-1);
            book[a][b-1][c-1] = k;
        }
        if (book[a][b-1][c] == 0)
        {
            l = w(a,b-1,c);
            book[a][b-1][c] = l;
        }
        return book[a][b][c-1] + book[a][b-1][c-1] + book[a][b-1][c];
    }
    long long q , s , e , r;
    if (book[a-1][b][c] == 0)
    {
        q = w(a-1,b,c);
        book[a-1][b][c] = q;
    }
    if (book[a-1][b-1][c] == 0)
    {
        s = w(a-1,b-1,c);
        book[a-1][b-1][c] = s;
    }
    if (book[a-1][b][c-1] == 0)
    {
        e = w(a-1,b,c);
        book[a-1][b][c-1] = e;
    }
    if (book[a-1][b-1][c-1] == 0)
    {
        r = w(a-1,b-1,c-1);
        book[a-1][b-1][c-1] = r;
    }
    return book[a-1][b][c]+book[a-1][b-1][c]+book[a-1][b][c-1]-book[a-1][b-1][c-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a , b , c;
    long long ans;
    while (cin >> a >> b >> c)
    {
        if ( a == -1 && b == -1 && c == -1)
        {
            break;
        }
        ans = w(a,b,c);
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans);
    }
    system("pause");
    return 0;
}