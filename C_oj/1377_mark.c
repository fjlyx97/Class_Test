#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int cnt;
    int num;
    struct node* next[26];
}node;
void insert_tree(char* str , node* root , int* max , char* max_str)
{
    node* p = root;
    int i = 0;
    int l = strlen(str);
    for ( i = 0 ; i < l ; i++)
    {
        if (p->next[str[i] - 'a'] == NULL)
        {
            p->next[str[i] - 'a'] = (node*)malloc(sizeof(node));
            p->next[str[i] - 'a']->cnt = 0;
            p->next[str[i] - 'a']->num = 0;
            memset(p->next[str[i] - 'a']->next,0,sizeof(p->next[str[i] - 'a']->next));
        }
        p = p->next[str[i] - 'a'];
        p->cnt += 1;
    }
    p->num++;
    if (p->num > *max)
    {
        *max = p->num; 
        strcpy(max_str,str);
    }
}
int main(void)
{
    node* root = (node*)malloc(sizeof(node));
    root->cnt = 0;
    root->num = 0;
    memset(root->next,0,sizeof(root->next));
    int N;
    scanf("%d",&N);
    char str[101];
    int max = 0;
    char max_str[101];
    while(N--)
    {
        scanf("%s",str);
        insert_tree(str,root,&max,max_str);
    }
    printf("%s",max_str);
    system("pause");
    return 0;
}