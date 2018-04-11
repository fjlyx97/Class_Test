#include <iostream>
using namespace std;
int numA[101] = {0};
int numB[101] = {0};
int numC[101] = {0};
int main()
{
    int A , B;
    int lena , lenb;
    int count = 0;
    cin >> A >> B;
    int i = 0;
    while (A)
    {
        numA[i] = A % 10;
        A /= 10;
        i++;
    }
    lena = i;
    i = 0;
    while (B)
    {
        numB[i] = B % 10;
        B /= 10;
        i++;
    }
    lenb = i;
    int carry = 0;
    int max_len = lena > lenb ? lena : lenb;
    for (i = 0 ; i < max_len ; i++)
    {
        numC[i] = numA[i] + numB[i] + carry;
        carry = numC[i] / 10;
        numC[i] = numC[i] % 10;
        if (carry > 0)
        {
            count++;
        }
    }
    while(carry)
    {
        numC[i] = carry % 10;
        carry /= 10; 
        if (carry > 0)
        {
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}