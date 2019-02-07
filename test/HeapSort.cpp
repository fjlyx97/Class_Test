#include <iostream>
#include <cstring>
using namespace std;
typedef struct Heap 
{
    int count;
    int num[1001];
    Heap() : count(0) 
    {
        memset(num,0,sizeof(num));
    }
}*HeapTree , HeapTreeNode;

void insertHeapNode(HeapTree root , int insertNum)
{
    int insertNumIndex = ++root->count;
    root->num[insertNumIndex] = insertNum;
    while (insertNumIndex / 2 > 0 && root->num[insertNumIndex] < root->num[insertNumIndex/2])
    {
        int temp = root->num[insertNumIndex];
        root->num[insertNumIndex] = root->num[insertNumIndex/2];
        root->num[insertNumIndex/2] = temp;
        insertNumIndex /= 2;
    }
}

int popHeapTopNode(HeapTree root)
{
    if (root->count <= 0)
        return -1;
    int popNum = root->num[1];
    root->num[1] = root->num[root->count--];
    int index = 1;
    int newIndex = 0;
    int maxPos;
    while (true)
    {
        maxPos = -1;
        if (index * 2 <= root->count && root->num[index] > root->num[index*2])
        {
            maxPos = root->num[index*2];
            newIndex = index*2;
        }
        if (index * 2 + 1 <= root->count && root->num[index*2+1] < root->num[index*2])
        {
            maxPos = root->num[index*2+1];
            newIndex = index*2+1;
        }
        if (maxPos == -1)
            break;

        int temp = root->num[index];
        root->num[index] = root->num[newIndex];
        root->num[newIndex] = temp;
        index = newIndex;
    }
    return popNum;
}

int main()
{
    HeapTree root = new HeapTreeNode;
    for (int i = 0 ; i < 100 ; i++)
    {
        int num;
        cin >> num;
        insertHeapNode(root,num);
    }
    for (int i = 0 ; i < 100 ; i++)
    {
        cout << popHeapTopNode(root) << " ";
    }

    delete root;
    system("pause");
    return 0;
}