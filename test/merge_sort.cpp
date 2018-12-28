#include <iostream>
using namespace std;
void merge(int *num , int *sort_num , int l , int r);
void merge_sort(int* num , int *sort_num , int l , int r)
{
    if (l >= r)
        return;
    int mid = (l+r)/2;
    merge_sort(num,sort_num,l,mid);
    merge_sort(num,sort_num,mid+1,r);
    merge(num,sort_num,l,r);
}
void merge(int *num , int *sort_num , int l , int r)
{
    int mid = (l+r)/2;
    int* newNum = new int[r-l+1];
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if (num[i] < num[j])
        {
            newNum[k++] = num[i];
            i++;
        }
        else
        {
            newNum[k++] = num[j];
            j++;
        }
    }
    while(i <= mid)
    {
        newNum[k++] = num[i++];
    }
    while(j <= r)
    {
        newNum[k++] = num[j++];
    }
    k = 0;
    for (int i = l ; i <= r ; i++)
    {
        sort_num[i] = newNum[k++];
    }

    delete[] newNum;
}
int main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    int *sort_num = new int[n];
    for (int i = 0 ; i < n ; i++)
    {
        cin >> num[i];
    }
    merge_sort(num,sort_num,0,n-1);
    for (int i = 0; i < n ; i++)
    {
        cout << sort_num[i] << " ";
    }
    cout << endl;
    delete[] num;
    delete[] sort_num;

    system("pause");
    return 0;
}