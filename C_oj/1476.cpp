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
            cout << temp_map[j][k] << " ";
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
int main()
{
    while (scanf("%d",&N) != EOF)
    {
        for (int i = 0 ; i < N ; i++)
        {
            cin >> map[i];
        }
        for (int i = 0 ; i < N ; i++)
        {
            cin >> ans_map[i];
        }
        /*开始搜索*/
        int flag = 1;
        for (int i = 1 ; i <= 3 ; i++)
        {
            /*正转*/
            for (int j = 0 ; j < N ; j++)
            {
                for (int k = 0 ; k < N ; k++)
                {
                    temp_map[j][k] = map[N-k-1][j];
                }
            }
            print();
            /*比较*/
            for (int j = 0 ; j < N ; j++)
            {
                if (strcmp(*(temp_map+j),*(map+j)))
                {
                    flag = 0;
                }
            }
            if (flag)
            {
                printf("YES");
                return 0;
            }
            /*上下翻转*/
            for (int j = 0 ; j < N/2 ; j++)
            {
                for (int k = 0 ; k < N ; k++)
                {
                    swap_str(temp_map[j][k],temp_map[N-j-1][k]);
                }
            }
            print();
            /*比较*/
            for (int j = 0 ; j < N ; j++)
            {
                if (strcmp(*(temp_map+j),*(map+j)))
                {
                    flag = 0;
                }
            }
            if (flag)
            {
                printf("YES");
                return 0;
            }
            system("pause");
        }
    }


    system("pause");
    return 0;
}