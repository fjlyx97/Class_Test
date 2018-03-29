#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream a , b;
    ofstream c;
    a.open("1.txt");
    b.open("2.txt");
    c.open("3.txt");
    string text;

    if ( a && b)
    {
        cout << "Open file success." << endl;
    }
    while(getline(a,text))
    {
        for (int i = 0 ; i < text.length() ; i++)
        {
            if (text[i] <= 'z' && text[i] >= 'a')
            {
                text[i] -= 32;
            }
            c << text[i];
        }
        c << "\r";
    }
    while(getline(b,text))
    {
        for (int i = 0 ; i < text.length() ; i++)
        {
            if (text[i] <= 'z' && text[i] >= 'a')
            {
                text[i] -= 32;
            }
            c << text[i];
        }
        c << "\r";
    }
    cout << "Write file success.";
    a.close();
    b.close();
    c.close();

    system("pause");
    return 0;
}