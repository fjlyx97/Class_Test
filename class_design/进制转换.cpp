#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
void transX2X(char num1[],int n, int m, char num2[]);//ת������
int main()
{
    char num1[101] , num2[101];
    int n , m;
    cout << "������Ҫת�������֣�";
    cin >> num1;
    cout << "����������ֵĽ�����:";
    cin >> n;
    cout << "������Ҫת���Ľ�����:";
    cin >> m;
    transX2X(num1,n,m,num2);
    system("pause");
    return 0;
}
void transX2X(char num1[],int n, int m, char num2[])//ת������
{
    int len = strlen(num1);
    int num = 0;
    int j = 0;
    for ( int i = len-1 ; i >= 0 ; i--)
    {
        num += (num1[i]-'0') * pow(n,len-1-i);
    }
    while(num)
    {
        if (num % m <= 9)
        {
            num2[j] = (num % m)+'0';
        }
        else
        {
            num2[j] = (num % m)-10 + 65;
        }
        num /= m;
        j++;
    }
    cout << "ת�����Ĵ�Ϊ��";
    for (int k = j-1 ; k >= 0 ; k--)
    {
        cout << num2[k];   
    }
    return;
}