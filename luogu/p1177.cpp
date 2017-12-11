#include <iostream>
using namespace std;
void swap(int i , int j , int* num)
{
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}
void quick_sort(int left , int right , int* num)
{
    if (left > right )
    {
        return;
    }
    int i = left;
    int j = right;
    int base_num = num[left];
    while( i != j)
    {
        for ( ; j > i ; j--)
        {
            if (num[j] < base_num)
            {
                break;
            }
        }
        for ( ; i < j ; i++)
        {
            if (num[i] > base_num)
            {
                break;
            }
        }       
        if ( i < j)
        {
            swap(i,j,num);
        }
    }
    swap(left,i,num);
    quick_sort(left,i-1,num);
    quick_sort(i+1,right,num);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int num[N];
    for ( int i = 0 ; i < N ; i++)
    {
        cin >> num[i];
    }
    quick_sort(0,N-1,num);
    for ( int i = 0 ; i < N ; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}