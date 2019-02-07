#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 50
struct A{
    int* num;
};
void print(A* newA)
{
    int b = 10;
    newA->num = &b;

}

int main()
{
    int num = 0;
    A a;
    a.num = &num;
    print(&a);

    system("pause");
    return 0;
}
