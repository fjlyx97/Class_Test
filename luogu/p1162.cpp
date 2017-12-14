#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int map[99][99];
int book[99][99];
typedef struct 
{
    int x;
    int y;
}queue;
queue map_queue[1024];
queue input_queue[1024];
int main()
{
    int N;
    int head = 1 , tail = 1;
    int input_head , input_tail = 1;
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    freopen("testdata.in","r",stdin);
    cin >> N;
    memset(map,0,sizeof(map));
    memset(book,0,sizeof(book));
    for ( int i = 1 ; i <= N ; i++)
    {
        for ( int j = 1 ; j <= N ; j++)
        {
            cin >> map[i][j];
        }        
    }

    map_queue[tail].x = 0;
    map_queue[tail].y = 0;
    tail++;
    int temp_x , temp_y;
    while ( head < tail )
    {
        for (int i = 0 ; i < 4 ; i++)
        {
            temp_x = map_queue[head].x + next[i][0];
            temp_y = map_queue[head].y + next[i][1];
            if (temp_x < 0 || temp_y < 0 || temp_x > N+1 || temp_y > N+1)
            {
                continue;
            }
            if ( book[temp_x][temp_y] == 0 && map[temp_x][temp_y] != 1)
            {
                book[temp_x][temp_y] = 1;
                map_queue[tail].x = temp_x;
                map_queue[tail].y = temp_y;
                input_queue[input_tail].x = temp_x;
                input_queue[input_tail].y = temp_y;
                input_tail++;
                tail++;
            }
        }
        //map[map_queue[head].x][map_queue[head].y] = 1;
        head++;
    }
    for ( int i = 1 ; i <= N ; i++)
    {
        for ( int j = 1 ; j <= N ; j++)
        {
            if (map[i][j] == 0 && book[i][j] == 0)
            {
                map[i][j] = 2;
            }
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    //while ( input_head < input_tail)
    //{
    //    map[input_queue[input_head].x][input_queue[input_head].y] = 0;
    //    input_head++;
    //}
    //for (int i = 1 ; i <= N ; i++)
    //{
    //    for (int j = 1 ; j <= N ; j++)
    //    {
    //        cout << map[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    system("pause");
    return 0;
}