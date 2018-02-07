#include <iostream>
#include <cstring>
using namespace std;
struct people
{
    char name[15];
    int input_money;
    int output_money;
}mypeople[11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    char temp_name[15];
    char temp1_name[15];
    int temp_money , temp_num;
    int temp;
    cin >> num;
    for ( int i = 1 ; i <= num ; i++)
    {
        cin >> mypeople[i].name; 
        mypeople[i].input_money = 0;
        mypeople[i].output_money = 0;
    }
    for ( int i = 1 ; i <= num ; i++)
    {
        cin >> temp_name;
        cin >> temp_money >> temp_num;
        if (temp_money != 0)
            temp = temp_money / temp_num;
        else
            temp = 0;
        for ( int j = 1 ; j <= num ; j++)
        {
            if (!strcmp(temp_name,mypeople[j].name))
            {
                mypeople[j].output_money = temp * temp_num;
                for (int k = 1 ; k <= temp_num ; k++)
                {
                    cin >> temp1_name;
                    for (int l = 1 ; l <= num ; l++)
                    {
                        if (!strcmp(temp1_name,mypeople[l].name))
                        {
                            mypeople[l].input_money += temp;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    for ( int i = 1 ; i <= num ; i++)
    {
        cout << mypeople[i].name << " " << mypeople[i].input_money-mypeople[i].output_money << endl;
    }
    system("pause");
    return 0;
}