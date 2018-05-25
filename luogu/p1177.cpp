#include <iostream>
using namespace std;
void merge(int* num , int* ans_num , int l , int r , int mid)
{
	int i = l , j = mid+1 , k = l;
	while ( i <= mid && j <= r)
	{
		if (num[i] < num[j])
		{
			ans_num[k++] = num[i++];
		}
		else
		{
			ans_num[k++] = num[j++];
		}
	}
	while (i <= mid)
	{
		ans_num[k++] = num[i++];
	}
	while (j <= r)
	{
		ans_num[k++] = num[j++];
	}
	for ( i = l ; i <= r ; i++)
	{
		num[i] = ans_num[i];
	}
}
void mergeSort(int l , int r , int* num , int* ans_num)
{
	int mid = (l+r)/2;
	if (l < r)
	{
		mergeSort(l , mid , num , ans_num);
		mergeSort(mid+1 , r , num , ans_num);
		merge(num,ans_num , l , r , mid);
	}
}
int num[101] = {0};
int ans_num[101] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	
	int i;
	cin >> n;
	for (i = 0 ; i < n ; i++)
	{
		cin >> num[i];
	}
	mergeSort(0,n-1,num,ans_num);
	for (i = 0 ; i < n ; i++)
	{
		cout << ans_num[i] << " ";
	}
	cout << endl;
	return 0;
}