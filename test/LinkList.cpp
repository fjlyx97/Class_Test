#include <iostream>
#include <stack>
using namespace std;

#define SUCCESS 1
#define ERROR 0
typedef int STATUS;

template <typename T>
class LinkList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node()
        {
            data = 0;
            next = NULL;
        }
    }*nodeHead,*nodeTail;

public:
    LinkList()
    {
        nodeHead = new Node();
        nodeTail = nodeHead;
    }
    ~LinkList()
    {
        Node* pNode = this->nodeHead;
        while(this->nodeHead != this->nodeTail)
        {
            this->nodeHead = this->nodeHead->next;
            delete pNode;
            pNode = nodeHead;
        }
        delete nodeTail;
    }
    
    STATUS insertNode(T insertNum)
    {
        Node* newNode = new Node;
        if (!newNode)
            return ERROR;
        this->nodeTail->next = newNode;
        this->nodeTail = newNode;
        this->nodeHead->data++;
        newNode->data = insertNum;
        newNode->next = this->nodeHead;
        return SUCCESS;
    }

    STATUS showNode()
    {
        Node* pNode = this->nodeHead->next;
        while(pNode != this->nodeTail)
        {
            cout << "Data is " << pNode->data << endl;
            pNode = pNode->next;
        }
        cout << "Data is " << this->nodeTail->data << endl;
        cout << endl;
        return SUCCESS;
    }

    STATUS showReverseNode()
    {
        Node* pNode = this->nodeHead->next;
        stack<T> mstack;
        while(pNode != this->nodeHead)
        {
            mstack.push(pNode->data);
            pNode = pNode->next;
        }
        while (!mstack.empty())
        {
            cout << "Data is " << mstack.top() << endl;
            mstack.pop();
        }
        cout << endl;
        return SUCCESS;
    }

};

int main()
{
    LinkList<int>* mList = new LinkList<int>;
    int temp;
    for (int i = 0 ; i < 10 ; i++)
    {
        cin >> temp;
        mList->insertNode(temp);
    }
    mList->showNode();
    mList->showReverseNode();
    delete mList;
    system("pause");
    return 0;
}

