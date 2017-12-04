#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a[13];
    for (int i = 0; i <= 12; i++) a[i] = i;
    int sum=0;
    do {
        if(a[1]>a[2]  ||a[2]>a[3]  ||a[3]>a[4])continue;
        if(a[5]>a[6]  ||a[6]>a[7]  ||a[7]>a[8])continue;
        if(a[9]>a[10] ||a[10]>a[11]||a[11]>a[12])continue;

        if(a[1]>a[5]||a[5]>a[9] )continue;
        if(a[2]>a[6]||a[6]>a[10])continue;
        if(a[3]>a[7]||a[7]>a[11])continue;
        if(a[4]>a[8]||a[8]>a[12])continue;

        sum++;
    } while (next_permutation(a+2, a+12));
    printf("%d\n",sum);
    system("pause");
    return 0;
}
