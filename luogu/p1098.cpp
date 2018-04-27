#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    int p1 , p2 , p3;
    char str[101];
    cin >> p1 >> p2 >> p3;
    cin >> str;
    int len = strlen(str);
    int loop;
    for (int i = 0 ; i < len ; i++)
    {
        if (str[i] == '-')
        {
            if(i == 0)
            {
                for (int l = i+1 ; l < len ; l++)
                {
                    if (str[l] != '-')
                    {
                        cout << str[l-1];
                        i = l-1;
                        break;
                    }
                    cout << str[l];
                }
                continue;
            }
            if (i == len-1)
            {
                cout << str[i];
                continue;
            }
            if (str[i+1] == '-')
            {
                for (int l = i+1 ; l < len ; l++)
                {
                    if (str[l] != '-')
                    {
                        cout << str[l-1];
                        i = l-1;
                        break;
                    }
                    cout << str[l];
                }
                continue;
            }
            if (str[i+1]-str[i-1] == 1)
            {
                continue;
            }
            else if (str[i+1]-str[i-1] <= 0)
            {
                cout << str[i];
                continue;
            }
            else if (('0' <= str[i-1] && str[i-1] <= '9') && (str[i+1] > '9'))
            {
                cout << str[i];
                continue;
            }
            else if (('0' <= str[i+1] && str[i+1] <= '9') && (str[i-1] > '9'))
            {
                cout << str[i];
                continue;
            }
            
            loop = str[i+1]-str[i-1]-1;
            char c;
            if (p3 == 1)
            {
                c = str[i-1]+1;
            }
            else
            {
                c = str[i+1]-1;
            }
            if ( '0' <= c && c <= '9')
            {
                c = c;
            }
            else
            {
                if (p1 == 1)
                    c = tolower(c);
                else if (p1 == 2)
                    c = toupper(c);
            }
            if (p1 == 3)
            {
                c = '*';
            }
            for (int j = 1 ; j <= loop ; j++)
            {
                for (int k = 1 ; k <= p2 ; k++)
                {
                    cout << c;   
                }
                if (p3 == 1)
                {
                    c++;
                }
                else
                {
                    c--;
                }
            }
        }       
        else
        {
            cout << str[i];
        }
    }
    cout << endl;
    system("pause");
    return 0;
}