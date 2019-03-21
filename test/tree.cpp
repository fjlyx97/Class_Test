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
        TreeNode* pLeft;
        TreeNode* pRight;
        TreeNode(ElemType mData)
        {
            data = mData;
            pLeft = NULL;
            pRight = NULL;
        }
    };

    TreeNode* treeRoot;
    string mExpression;

private:
    void updateTree()
    {
        queue<TreeNode*> mQueue;
        stack<TreeNode*> symbolStack;
        ElemType temp;
        for (int i = 0 ; i < mExpression.length() ; i++)
        {
            temp = mExpression.at(i);
            TreeNode* newTreeNode = new TreeNode(temp);
            if (temp != '+' && temp != '-' && temp != '*' && temp != '/' && temp != '(' && temp != ')')
                mQueue.push(newTreeNode);
            else
            {
                while (!symbolStack.empty())
                {
                    if (temp == '+' || temp == '-')
                    {
                        TreeNode* topSymbol = symbolStack.top();
                        if (topSymbol->data != '(')
                        {
                            mQueue.push(topSymbol);
                            symbolStack.pop();
                        }
                        else
                            break;
                    }
                    else if (temp == '*' || temp == '/')
                    {
                        TreeNode* topSymbol = symbolStack.top();
                        if (topSymbol->data != '(' || topSymbol->data != '+' || topSymbol->data != '-')
                        {
                            mQueue.push(topSymbol);
                            symbolStack.pop();
                        }
                        else
                            break;
                    }
                    else if (temp == '(')
                        break;
                    else if (temp == ')')
                    {
                        TreeNode* topSymbol = symbolStack.top();
                        while (topSymbol->data != '(')
                        {
                            TreeNode* topSymbol = symbolStack.top();
                            mQueue.push(topSymbol);
                            symbolStack.pop();
                        }
                        symbolStack.pop();
                        break;
                    }
                }
                symbolStack.push(newTreeNode);
            }
        }

        while (!symbolStack.empty())
        {
            mQueue.push(symbolStack.top());
            symbolStack.pop();
        }

        while (!mQueue.empty())
        {
            cout << (mQueue.front())->data;
            mQueue.pop();
        }
    }

public:
    Tree(string expression) : mExpression(expression)
    {
        updateTree();
    }
    ~Tree()
    {

    }
};

int main()
{
    Tree<char> mTree("9+(3-1)*3+10/2");

    system("pause");
    return 0;
}