#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
char map[15][15];
char temp_map[15][15];
char ans_map[15][15];
int N;
void print()
{
//测试数据
    for (int j = 0 ; j < N ; j++)
    {
        for (int k = 0 ; k < N ; k++)
        {
            cout << map[j][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void swap_str(char& a , char& b)
{
    char t;
    t = a;
    a = b;
    b = t;
}
int ans_flag = 0;
void dfs(int step)
{
    int flag = 1;
    if (step == 4 || ans_flag == 1)
    {
        return;
    }
    /*判定是否符合条件*/
    for (int j = 0 ; j < N ; j++)
    {
        if (strcmp(*(ans_map+j),*(map+j)) != 0)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        //print();
        ans_flag = 1;
        return;
    }
    /*保存地图方便回溯*/
    char save_map[15][15];
    //cout << "SaveMap:" << endl;
    for (int i = 0 ; i < N ; i++)
    {
        strcpy(save_map[i],map[i]);
        //cout << save_map[i] << endl;
    }
    /*开始搜索*/
    /*正转*/
    for (int j = 0 ; j < N ; j++)
    {
        for (int k = 0 ; k < N ; k++)
        {
            temp_map[j][k] = map[N-k-1][j];
        }
    }
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],temp_map[j]);
    }
    dfs(step+1);
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],save_map[j]);
    }
    /*逆转*/
    for (int j = 0 ; j < N ; j++)
    {
        for (int k = 0 ; k < N ; k++)
        {
            temp_map[j][k] = map[k][N-j-1];
        }
    }
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],temp_map[j]);
    }
    dfs(step+1);
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],save_map[j]);
    }
    /*上下翻转*/
    for (int j = 0 ; j < N ; j++)
    {
        for (int k = 0 ; k < N ; k++)
        {
            temp_map[j][k] = map[N-j-1][k];
        }
    }
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],temp_map[j]);
    }
    dfs(step+1);
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],save_map[j]);
    }
    /*左右翻转*/
    for (int j = 0 ; j < N ; j++)
    {
        for (int k = 0 ; k < N ; k++)
        {
            temp_map[j][k] = map[j][N-k-1];
        }
    }
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],temp_map[j]);
    }
    //cout << step << endl;
    //print();
    dfs(step+1);
    for (int j = 0 ; j < N ; j++)
    {
        strcpy(map[j],save_map[j]);
    }
    return;
}
int main()
{
    while (scanf("%d",&N) != EOF)
    {
        ans_flag = 0;
        for (int i = 0 ; i < N ; i++)
        {
            cin >> map[i];
        }
        for (int i = 0 ; i < N ; i++)
        {
            cin >> ans_map[i];
        }
        dfs(1);
        if (ans_flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    system("pause");
    return 0;
}