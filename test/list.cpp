#include <iostream>
using namespace std;
template <typename ElemType>
class LinkList
{
private:
    struct ListNode
    {
        ElemType data;
        ListNode* next;
        ListNode(ElemType mData) : data(mData) , next(NULL) {}
    };

    ListNode* linkListHead;
    ListNode* linkListTail;

public:
    LinkList() : linkListHead(NULL) , linkListTail(NULL) {}
    ~LinkList() {}

    bool insertNode(ElemType insertNum)
    {
        ListNode* newListNode = new ListNode(insertNum);
        if (!newListNode)
            return false;
        if (!linkListHead)
        {
            this->linkListHead = this->linkListTail = newListNode;
            return true;
        }
        linkListTail->next = newListNode;
        linkListTail = newListNode;
        return true;
    }

    bool printLinkList()
    {
        ListNode* pListNode = this->linkListHead;
        while (pListNode)
        {
            cout << pListNode->data << " ";
            pListNode = pListNode->next;
        }
        cout << endl;
        return true;
    }

    bool deleteNode(ElemType deleteNum)
    {
        ListNode* pListNode = this->linkListHead;
        ListNode* preListNode = this->linkListHead;
        if (this->linkListHead->data == deleteNum)
        {
            this->linkListHead = this->linkListHead->next;
            delete pListNode;
            return true;
        }
        while(pListNode)
        {
            if (pListNode->data == deleteNum)
            {
                preListNode->next = pListNode->next;
                delete pListNode;
                return true;
            }
            preListNode = pListNode;
            pListNode = pListNode->next;
        }
        return false;
    }

    ListNode* locateNode(ElemType locateNum)
    {
        ListNode* pListNode = this->linkListHead;
        while(pListNode)
        {
            if (pListNode->data == locateNum)
                return pListNode;
            pListNode = pListNode->next;
        }
        return NULL;
    }
};
int main()
{
    LinkList<int> mList;
    for (int i = 0 ; i < 10 ; i++)
    {
        mList.insertNode(i*2);
    }
    mList.printLinkList();
    mList.deleteNode(0);
    mList.deleteNode(6);
    mList.deleteNode(18);
    mList.printLinkList();
    cout << mList.locateNode(2) << endl;

    return 0;
}