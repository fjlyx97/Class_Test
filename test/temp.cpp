#include <iostream>
#include <ctime>
using namespace std;
void recursive(int n)
{
	if (n < 1)
		return;
	recursive(n - 1);
	cout << n << " ";
}
void circle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << i << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	clock_t startTime = clock();
	//circle(n);
	recursive(n);
	clock_t finishTime = clock();
	double consumeTime = double(finishTime - startTime) / CLOCKS_PER_SEC;
	cout << "consume time : " << consumeTime << endl;
	system("pause");
	return 0;
}
