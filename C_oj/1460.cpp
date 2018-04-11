#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int x0 , y0;
    char cmd;
    char cmds[101];
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int status;
    cin >> x0 >> y0 >> cmd;
    getchar();
    switch (cmd)
    {
        case 'N':
            status = 0;
            break;
        case 'E':
            status = 1;
            break;
        case 'S':
            status = 2;
            break;
        case 'W':
            status = 3;
            break;
    }

    gets(cmds);
    for (int i = 0 ; i < strlen(cmds) ; i++)
    {
        if (cmds[i] == 'R')
        {
            status += 1;
            if (status > 3)
            {
                status -= 4;
            }
        }
        else if (cmds[i] == 'L')
        {
            status -= 1;
            if (status < 0)
            {
                status += 4;
            }
        }
        else if (cmds[i] == 'G')
        {
            x0 += next[status][0];
            y0 += next[status][1];
        }
    }
    cout << x0 << " " << y0 << " ";
    if (status == 0)
    {
        cout << 'N';
    }
    else if (status == 1)
    {
        cout << 'E';
    }
    else if (status == 2)
    {
        cout << 'S';
    }
    else
    {
        cout << 'W';
    }
    system("pause");
    return 0;
}