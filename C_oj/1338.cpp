#include <iostream>
#include <cstring>
using namespace std;
struct my_stack
{
	int index;
	char str[10];
}stack[20001];
int main()
{
	int N;
	int max = -1;
	int temp;
	cin >> N;
	for ( int i = 1 ; i <= N ; i++)
	{
		cin >> stack[i].str;
		stack[i].index = i;
		if (!strcmp(stack[i].str,"else"))
		{
			for (int j = i-1 ; j >= 1 ; j--)
			{
				if (!strcmp(stack[j].str,"if"))
				{
					temp = (stack[i].index - stack[j].index) / 2;
					if (temp > max)
					{
						max = temp;
					}
					strcpy(stack[i].str,"-1");
					strcpy(stack[j].str,"-1");
					break;
				}
			}
		}
	}
	for ( int k = 1 ; k <= N ; k++)
	{
		if (!strcmp(stack[k].str,"if"))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << max << endl;
	return 0;
}