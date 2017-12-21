#include <iostream>
using namespace std;
typedef struct myqueue
{
    int index;
    struct myqueue* next;
}queue;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    queue* head = new queue;
    head->index = 1;
    head->next = NULL;
    queue* phead = head;
    for ( int i = 2 ; i <= n ; i++)
    {
        if ( i == n )
        {
            queue * people = new queue;
            people->index = i;
            people->next = head;
            phead->next = people;
            phead = phead->next;
            break;
        }
        queue * people = new queue;
        people->index = i;
        people->next = NULL;
        phead->next = people;
        phead = phead->next;
    }
    int index = 0;
    while(n)
    {
        index++;
        if (index % m == 0)
        {
            cout << head->index << " ";
            head = head->next;
            phead->next = head;
            n--;
            continue;
        }
        head = head->next;
        phead = phead->next;
    }
    cout << endl;
    system("pause");
    return 0;
}