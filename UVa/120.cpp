#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
void myswap(int *num , int begin , int over)
{
    while(begin >= over)
    {
        swap(num[begin] , num[over]);
        begin--;
        over++;
    }
}
bool judge(int *num , int j)
{
    for (int i = 0 ; i < j-1 ; i++)
    {
        if (num[i] > num[i+1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string line;
    int num[31];
    int i = 0;
    
    while (getline(cin,line))
    {
        cout << line << endl;
        stringstream str_num(line);
        while (str_num >> num[i])
        {
            i++;
        }
        //search maxnumber
        int temp = i;
        int mark_index = i-1; //记录元素数量
        int tail = i-1; //尾巴下标
        while(1)
        {
            if (judge(num,i))
            {
                cout << "0";
                break;
            }
            int index;
            int max_num = num[0];
            for (int k = 0 ; k < tail+1 ; k++)
            {
                if (num[k] >= max_num)
                {
                    max_num = num[k];
                    index = k;
                }
            }
            if (index == tail)
            {
                mark_index--;
                temp--;
                tail--;
                continue;
            }
            if (mark_index-index+1 != temp)
            {
                cout << i-index << " ";
                myswap(num,index,0);
            }
            myswap(num,tail,0);
            cout << i-tail << " ";
            tail--;
        }
        i = 0;
        cout << endl;
    }
    system("pause");
    return 0;
}