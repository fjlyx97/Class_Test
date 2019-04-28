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
        TreeNode* pLeft;
        TreeNode* pRight;
        bool isVisit;
        TreeNode(char SaveChar , int Weight) : saveChar(SaveChar) , weight(Weight) , isVisit(false) , pLeft(NULL) , pRight(NULL) {}
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
            newNode->pLeft = firstNode;
            newNode->pRight = secondNode;
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

    void showCoding()
    {
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
    }
};
int main()
{
    HuffmanTree huffmanTree("helloworld");
    huffmanTree.showSendString();
    huffmanTree.showCoding();



    system("pause");
    return 0;
}