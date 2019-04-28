#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
//26小写英文
class HuffmanTree
{
private:
    struct TreeNode
    {
        char saveChar;
        int weight;
        TreeNode* parent;
        TreeNode* pLeft;
        TreeNode* pRight;
        bool isVisit;
        stack<int> path;
        TreeNode(char SaveChar , int Weight) : saveChar(SaveChar) , weight(Weight) , isVisit(false) , parent(NULL) , pLeft(NULL) , pRight(NULL) {}
    };
    struct cmp
    {
        bool operator()(const TreeNode* A , const TreeNode* B)
        {
            return A->weight > B->weight;
        }
    };
private:
    string initString;
    int countChar[27];
    priority_queue<TreeNode*,vector<TreeNode*>,cmp> tree;
    vector<TreeNode*> treeLeaf;
    TreeNode* treeRoot;

public:
    HuffmanTree(string InitString) : initString(move(InitString)) 
    {
        memset(countChar,0,sizeof(countChar));
        for (int i = 0 ; i < initString.size() ; i++)
            countChar[initString[i]-'a'+1]++;
        for (int i = 1 ; i < 27 ; i++)
        {
            if (countChar[i] == 0)
                continue;
            TreeNode* newNode = new TreeNode(i-1+'a',countChar[i]);
            tree.push(newNode);
        }
        while(!tree.empty() && tree.size() != 1)
        {
            TreeNode* firstNode = tree.top();
            tree.pop();
            TreeNode* secondNode = tree.top();
            tree.pop();
            TreeNode* newNode = new TreeNode(' ',firstNode->weight+secondNode->weight);
            if (!firstNode->pLeft && !firstNode->pRight)
                treeLeaf.push_back(firstNode);
            if (!secondNode->pLeft && !secondNode->pRight)
                treeLeaf.push_back(secondNode);
            newNode->pLeft = firstNode;
            newNode->pRight = secondNode;
            firstNode->parent = newNode;
            secondNode->parent = newNode;
            tree.push(newNode);
        }
        treeRoot = tree.top();
    }

    void showSendString()
    {
        cout << "String : " << this->initString << endl;
    }

    void showTree()
    {
        while(!tree.empty())
        {
            cout << tree.top()->saveChar << endl;
            tree.pop();
        }
    }

    void encode()
    {
#if 0
        stack<TreeNode*> treeStack;
        TreeNode* currentNode = treeRoot;
        while (currentNode || !treeStack.empty())
        {
            while(currentNode)
            {
                treeStack.push(currentNode);
                if (!currentNode->isVisit)
                    currentNode->isVisit = true;
                currentNode = currentNode->pLeft;
            }
            if (!treeStack.empty())
            {
                currentNode = treeStack.top();
                treeStack.pop();
                if (currentNode->saveChar != ' ')
                    cout << "Char is " << currentNode->saveChar << " Weight is " << currentNode->weight << endl;
                currentNode = currentNode->pRight;
            }
        }
#endif
        vector<TreeNode*>::iterator iter = treeLeaf.begin();
        for ( ; iter != treeLeaf.end() ; iter++)
        {
            stack<int> temp;
            TreeNode* currentNode = *iter;
            TreeNode* currentNodeParent = currentNode->parent;
            cout << "Char is " << currentNode->saveChar << " Weight is " << currentNode->weight << endl;
            while(currentNodeParent)
            {
                if (currentNodeParent->pLeft == currentNode)
                    temp.push(0);
                else
                    temp.push(1);
                currentNode = currentNodeParent;
                currentNodeParent = currentNode->parent;
            }
            while (!temp.empty())
            {
                cout << temp.top();
                temp.pop();
            }
            cout << endl;
        }
    }
    void decode(string decodeString)
    {
        cout << "Decode : ";
        TreeNode* currentNode = treeRoot;
        for (int i = 0 ; i < decodeString.size() ; i++)
        {
            if (decodeString[i] == '0')
                currentNode = currentNode->pLeft;
            else
                currentNode = currentNode->pRight;
            if (!currentNode->pLeft && !currentNode->pRight)
            {
                cout << currentNode->saveChar;
                currentNode = treeRoot;
            }
        }
        cout << endl;
    }
};
int main()
{
    HuffmanTree huffmanTree("helloworld");
    huffmanTree.showSendString();
    huffmanTree.encode();
    huffmanTree.decode(move("101110011110100101000111010"));
    huffmanTree.decode(move("10111011101110111011"));



    system("pause");
    return 0;
}