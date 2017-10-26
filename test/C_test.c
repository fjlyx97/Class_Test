#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <math.h>
int main(void)
{
    int a = 9;
    int b = 2;
    float x = 8.8, y = 1.1, z;
    z = a / 2 + b * x / y + 1 / 2;
    printf("%5.2f\n",z);

    //int a = 2;
    //a %= 4 - 1;
    //printf("%d,",a);
    //a -= a *= 3;
    //a += a *= a -= a *= 3;
    //printf("%d",a);



    //int x = 4 , y = 0 , z;
    //x *= 3 + 2;
    //printf("%d",x);
    //x *= y = z = 4;
    //printf("%d",x);



    //printf("%d",'9');

    //int x , y , z;
    //x = ( y = ( z = 10) + 5) - 5;
    //printf("%d",x);


    //char ch1,ch2,ch3;
    //ch1 = getchar();
    //ch2 = getchar();
    //ch3 = getchar();
    //putchar(ch1);
    //putchar(ch2);
    //putchar(ch3);
    //putchar('\n');     

    //int a;
    //float b,c;
    //scanf("%2d%3f%4f",&a,&b,&c);
    //printf("\n a=%d , b = %f , c = %f\n",a , b, c);
    //char ch1[51],ch2[51];
    //int i,b;
    //gets(ch1);
    //b=strlen(ch1);
    //for(i=0;i<50;i++)
    //{
    //    ch2[b-i-1]=ch1[i];
    //    if(b-i==0) break;
    //}
    //printf("%s",strcat(ch1,ch2));

    
    //int x = 023;
    //printf("%x \n",--x);
    //int i = 0;
    //int j = 1;
    //i = i + j++;
    //printf("%d,%d,%d\n",i++,++j,i); 

    //char a , b , c, d;
    //b = '\xbc';
    //d = '\023';
    //printf("%c %c\n", b, d);   

    //int x , y;
    //x = 5;
    //y = x++ * x++;
    //y = --y * --y; 
    //int num[5] = {1,2,3,4,5};
    //printf("%d",*(num+3));
    //printf("%d %d %d\n",'k' , 'e' , 'y');
    //char a[10];
    //scanf("%s",a);
    //if ( !strcmp(a,"key"))
    //{
    //    printf("ok");
    //}   
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