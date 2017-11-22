#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num1, num2;
    char op;
    scanf("%d%c%d",&num1,&op,&num2);
    switch(op)
    {
        case '+':
            printf("%d%c%d=%d",num1,op,num2,num1+num2);
            break;
        case '-':
            printf("%d%c%d=%d",num1,op,num2,num1-num2);
            break;
        case 'x':
            printf("%d%c%d=%d",num1,op,num2,num1*num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("divide by 0!");
                break;
            }
            else
            {
                printf("%d%c%d=%.2f",num1,op,num2,(float)num1/num2);
                break;
            }
        default:
            printf("error input!");
    }

    system("pause");
    return 0;
}