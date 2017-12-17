#include <iostream>
using namespace std;
int A[201];
int B[201];
int win[5][5] = {{-1,0,1,1,0},{1,-1,0,1,0},{0,1,-1,0,1},{0,0,1,-1,1},{1,1,0,0,-1}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , NA , NB;
    cin >> N >> NA >> NB;
    for ( int i = 1 ; i <= NA ; i++)
    {
        cin >> A[i];
    }
    for ( int i = 1 ; i <= NB ; i++)
    {
        cin >> B[i];
    }
    int numA = 0, numB = 0;
    int indexA = 1, indexB = 1;
    for ( int i = 1 ; i <= N ; i++)
    {
        if (win[A[indexA]][B[indexB]] == 1)
        {
            numA++;
        }
        else if (win[A[indexA]][B[indexB]] == 0)
        {
            numB++;
        }
        indexA++;
        indexB++;
        if (indexA == NA+1)
        {
            indexA = 1;
        }
        if (indexB == NB+1)
        {
            indexB = 1;
        }
    }
    cout << numA << " " << numB << endl;

    system("pause");
    return 0;
}