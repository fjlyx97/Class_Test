#include <stdio.h>
#include <stdlib.h>
typedef struct my_toys
{
    int status; //0内，1外
    char name[11];
    struct my_toys * down;
    struct my_toys * up;
}toys;
int main(void)
{
    int n , m;
    scanf("%d %d", &n, &m);
    toys my_toys[n];
    int i = 0;
    toys* head , end;
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d ",&my_toys[i].status);
        scanf("%s",my_toys[i].name);
        if ( 0 == i )
        {
            head = &my_toys[0];
        }
        if ( n-1 != i)
        {
            my_toys[i].down = &my_toys[i+1];
        }
        else
        {
            my_toys[n-1].down = &my_toys[0];
        }
        if ( 0 != i)
        {
            my_toys[i].up = &my_toys[i-1];
        }
        else
        {
            my_toys[0].up = &my_toys[n-1];
        }
    }
    int a , s;
    int fangxiang;
    int j = 0;
    for ( i = 0 ; i < m ; i++)
    {
        scanf("%d %d",&a , &s);
        fangxiang = head->status;
        if ( 0 == fangxiang ) //0内1外
        {
            if ( 0 == a)
            {
                for ( j = 0 ; j < s ; j++)
                {
                    head = head->up;
                }
            }
            else
            {
                for ( j = 0 ; j < s ; j++)
                {
                    head = head->down;
                }
            }
        }
        else
        {
            if ( 0 == a)
            {
                for ( j = 0 ; j < s ; j++)
                {
                    head = head->down;
                }
            }
            else
            {
                for ( j = 0 ; j < s ; j++)
                {
                    head = head->up;
                }
            }
        }
    }
    printf("%s",head->name);
    system("pause");
    return 0;
}