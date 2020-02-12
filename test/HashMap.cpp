#include <iostream>
using namespace std;
class HashList
{
private:
    struct HashNode
    {
        int num;
        HashNode* next;
        HashNode() : next(NULL) , num(0) {}
    };
    int length;
    HashNode* hashListNum;

public:
    HashList():length(15)
    {
        hashListNum = new HashNode[length];
    }

    ~HashList()
    {
        for (int i = 0 ; i < this->length ; i++)
        {
            HashNode* currentNode = this->hashListNum[i].next;
            HashNode* preNode = currentNode;
            while(preNode)
            {
                if (currentNode->next)
                    currentNode = currentNode->next;
                else
                    currentNode = NULL;
                
                delete preNode;
                preNode = currentNode;
            }
        }
        delete[] this->hashListNum;
    }

    void insertNode(int num)
    {
        int key = num % 15;
        HashNode* newNode = new HashNode;
        newNode->num = num;
        HashNode* currentNode = &this->hashListNum[key];
        while(currentNode->next)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }

    HashNode* locateNode(int num)
    {
        int key = num % 15;
        HashNode* currentNode = &this->hashListNum[key];
        while(currentNode->next)
        {
            if (currentNode->num == num)
                return currentNode;
            currentNode = currentNode->next;
        }
        return NULL;
    }
};
int main()
{
    HashList list;
    int num;
    for(int i = 0 ; i < 12 ; i++)
    {
        //105 97 28 52 37 22 16 90 45 79 59 76
        cin >> num;
        list.insertNode(num);
    }
    cout << list.locateNode(97) << endl;
    cout << list.locateNode(100) << endl;
    system("pause");
    return 0;
}