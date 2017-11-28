#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    getchar();
    int i = 0;
    char str[101];
    //char* str = (char*)malloc(sizeof(char) * 102);
    int book[10000] = {0};
    //int* book = (int*)malloc(sizeof(int) * 1000);
    //for ( i = 0 ; i < 1000 ; i++)
    //{
    //    book[i] = 0;
    //}
    char save_str[10000][101];
    //char** save_str = (char**)malloc(sizeof(char*) * 1000);
    //for ( i = 0 ; i < N ; i++)
    //{
    //    save_str[i] = (char*)malloc(sizeof(char*) * 101);
    //}
    int len = 0;
    int status;
    while (N--)
    {
        scanf("%s",str);    
        status = 0;
        for ( i = 0 ; i < len ; i++)
        {
            if (strcmp(str,save_str[i]) == 0)
            {
                status = 1;
                book[i] += 1;
                break;
            }
        }
        if (status == 0)
        {
            strcpy(save_str[len],str);
            book[len] += 1;
            len++;
        }
    }
    int max = 0, index = 0;
    for (i = 0 ; i < len ; i++)
    {
        if (book[i] > max)
        {
            index = i;
            max = book[i];
        }
    }
    printf("%s",save_str[index]);
    system("pause");
    return 0;
}