#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
template <typename ElemType>
class Tree
{
private:
    struct TreeNode
    {
        ElemType data;
        bool isVisit;
        TreeNode* pLeft;
        TreeNode* pRight;
        TreeNode(ElemType mData)
        {
            data = mData;
            isVisit = false;
            pLeft = NULL;
            pRight = NULL;
        }
    };
    queue<TreeNode*> mQueue;  //储存后缀表达式
    stack<TreeNode*> symbolStack; //储存中转符号
    stack<TreeNode*> binaryTree;

    TreeNode* treeRoot;
    string mExpression;

private:
    void updatePostfixExpression()
    {
        ElemType temp;
        int flag;
        for (int i = 0 ; i < mExpression.length() ; i++)
        {
            temp = mExpression.at(i);
            TreeNode* newTreeNode = new TreeNode(temp);
            flag = 1;
            if (temp != '+' && temp != '-' && temp != '*' && temp != '/' && temp != '(' && temp != ')')
            {
                //cout << newTreeNode->data << endl;
                this->mQueue.push(newTreeNode);
            }
            else
            {
                while (!this->symbolStack.empty())
                {
                    if (temp == '+' || temp == '-')
                    {
                        TreeNode* topSymbol = this->symbolStack.top();
                        if (topSymbol->data != '(')
                        {
                            this->mQueue.push(topSymbol);
                            this->symbolStack.pop();
                        }
                        else
                            break;
                    }
                    else if (temp == '*' || temp == '/')
                    {
                        TreeNode* topSymbol = this->symbolStack.top();
                        if (topSymbol->data != '+' && topSymbol->data != '-' && topSymbol->data != '(')
                        {
                            this->mQueue.push(topSymbol);
                            this->symbolStack.pop();
                        }
                        else
                            break;
                    }
                    else if (temp == '(')
                        break;
                    else if (temp == ')')
                    {
                        TreeNode* topSymbol = this->symbolStack.top();
                        while (true)
                        {
                            topSymbol = this->symbolStack.top();
                            if (topSymbol->data == '(')
                                break;
                            this->mQueue.push(topSymbol);
                            this->symbolStack.pop();
                        }
                        this->symbolStack.pop();
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    this->symbolStack.push(newTreeNode);
            }
        }

        while (!this->symbolStack.empty())
        {
            this->mQueue.push(this->symbolStack.top());
            this->symbolStack.pop();
        }
#if 0
        while (!this->mQueue.empty())
        {
            cout << (this->mQueue.front())->data;
            this->mQueue.pop();
        }
#endif
    }

    void updateTree()
    {
        queue<int> q;
        TreeNode* currentNode;
        while(!this->mQueue.empty())
        {
            currentNode = this->mQueue.front();
            if (currentNode->data != '+' && currentNode->data != '-' && currentNode->data != '*' && currentNode->data != '/')
            {
                this->binaryTree.push(currentNode);
            }
            else
            {
                TreeNode* firstNode = this->binaryTree.top();
                this->binaryTree.pop();
                TreeNode* secondNode = this->binaryTree.top();
                this->binaryTree.pop();
                currentNode->pRight = firstNode;
                currentNode->pLeft = secondNode;
                this->binaryTree.push(currentNode);
            }

            this->mQueue.pop();
        }
        this->treeRoot = this->binaryTree.top();
        this->binaryTree.pop();
#if 0
        cout << endl;
        cout << this->binaryTree.size() << endl;
#endif
    }

public:
    Tree(string expression) : mExpression(expression)
    {
        updatePostfixExpression();
        updateTree();
    }

    ~Tree()
    {
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(this->treeRoot);
        TreeNode* currentNode;
        while(!bfsQueue.empty())
        {
            currentNode = bfsQueue.front();
            if (currentNode->pLeft != NULL)
                bfsQueue.push(currentNode->pLeft);
            if (currentNode->pRight != NULL)
                bfsQueue.push(currentNode->pRight);
            bfsQueue.pop();
            delete currentNode;
        }
    }

    void showTree()  //打印二叉树
    {
        //BFS进行层次遍历
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(this->treeRoot);
        TreeNode* currentNode;
        int currentPushed = 1;
        int hasPushed = 1;

        while(!bfsQueue.empty())
        {
            currentNode = bfsQueue.front();

            cout << currentNode->data << " ";
            currentPushed--;
            hasPushed--;

            if (currentNode->pLeft != NULL)
            {
                bfsQueue.push(currentNode->pLeft);
                hasPushed++;
            }
            if (currentNode->pRight != NULL)
            {
                bfsQueue.push(currentNode->pRight);
                hasPushed++;
            }
            bfsQueue.pop();

            if (currentPushed == 0)
            {
                currentPushed = hasPushed;
                cout << endl;
            }
        }
        cout << endl;
    }

    void preorderShow()
    {
        stack<TreeNode*> saveNode;
        TreeNode* currentNode = this->treeRoot;
        while(currentNode || !saveNode.empty())
        {
            while(currentNode)
            {
                cout << currentNode->data << " ";
                saveNode.push(currentNode);
                currentNode = currentNode->pLeft;
            }
            if (!saveNode.empty())
            {
                currentNode = saveNode.top();
                saveNode.pop();
                currentNode = currentNode->pRight;
            }
        }
        cout << endl;
    }

    void inorderShow()
    {
        stack<TreeNode*> saveNode;
        TreeNode* currentNode = this->treeRoot;
        while(currentNode || !saveNode.empty())
        {
            while (currentNode)
            {
                saveNode.push(currentNode);
                currentNode = currentNode->pLeft;
            }
            if (!saveNode.empty())
            {
                currentNode = saveNode.top();
                cout << currentNode->data << " ";
                saveNode.pop();
                currentNode = currentNode->pRight;
            }
        }
        cout << endl;
    }

    void postorderShow()
    {
        stack<TreeNode*> saveNode;
        TreeNode* currentNode = this->treeRoot;
        while(currentNode || !saveNode.empty())
        {
            while (currentNode)
            {
                saveNode.push(currentNode);
                currentNode = currentNode->pLeft;
            }
            if (!saveNode.empty())
            {
                TreeNode* temp = saveNode.top();
                saveNode.pop();
                if (temp->isVisit == false)
                {
                    temp->isVisit = true;
                    saveNode.push(temp);
                    currentNode = temp->pRight;
                }
                else
                {
                    cout << temp->data << " ";
                    currentNode = NULL;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    // a b * c d e * f / + g + -
    //Tree<char> mTree("a*b-((c+d*e/f)+g)");
    Tree<char> mTree("(a+b*(c-d))-e/f");
#if 1
    mTree.showTree();
    mTree.preorderShow();
    mTree.inorderShow();
    mTree.postorderShow();
#endif

    return 0;
}