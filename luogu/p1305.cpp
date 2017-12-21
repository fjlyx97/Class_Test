#include <iostream>
#include <cstdio>
using namespace std;
char tree[9999] = {0};
void print_tree(int i ,int n)
{
    if (i > 9999)
    {
        return;
    }
    if (tree[i] != '*' && tree[i] != '\0')
    {
        cout << tree[i];
    }
    print_tree(i*2,n);
    print_tree(i*2+1,n);
}
int main()
{
    int n;
    cin >> n;
    char input_str[4];
    cin >> input_str;
    tree[1] = input_str[0];
    tree[2] = input_str[1];
    tree[3] = input_str[2];
    int n_temp = n-1;
    while (n_temp--)
    {
        cin >> input_str;
        for ( int j = 1 ; j < 9999 ; j++)
        {
            if (input_str[0] == tree[j])
            {
                tree[j*2] = input_str[1];
                tree[j*2+1] = input_str[2];
            }
        }
    }
    print_tree(1,n);
    system("pause");
    return 0;
}