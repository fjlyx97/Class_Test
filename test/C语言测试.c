#include "stdio.h"
#include "stdlib.h"
int main()
{
    printf("helloworld \n");
    char a[] = "myname";
    printf("%2s \n" , a);  //myname
    printf("%04d \n" , 14); //0014
    printf("%.4f \n" , 32.4); //32.4000
    printf("%2.3f \n" , 234.3); //234.300
    system("pause");
    return 0;
}