#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <math.h>
int main()
{
    printf("%d %d %d\n",'k' , 'e' , 'y');
    char a[10];
    scanf("%s",a);
    if ( !strcmp(a,"key"))
    {
        printf("ok");
    }   


    //int c = 3 * 0.5;
    //printf("%f",3*0.5);
    //printf("%d",2.0/0);
    //printf("%d",'9'); //0 : 48 4:52  9:57
    //printf("helloworld \n");
    //char a[] = "myname";
    //printf("%2s \n" , a);  //myname
    //printf("%04d \n" , 14); //0014
    //printf("%.4f \n" , 32.4); //32.4000
    //printf("%2.3f \n" , 234.3); //234.300
    system("pause");
    return 0;
}