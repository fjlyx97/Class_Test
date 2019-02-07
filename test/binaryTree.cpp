//核心思路，依次对比节点，小的放右边，大的放左边
#include <iostream>
#include <queue>
using namespace std;
typedef struct _treeNode
{
    int data;
    _treeNode* treeLeft;
    _treeNode* treeRight;
}TreeNode,*Tree;

Tree createTree(int insertData)
{
    Tree newTree = new TreeNode;
    newTree->data = insertData;
    newTree->treeLeft = NULL;
    newTree->treeRight = NULL;
    return newTree;
}

void insertTreeNode(Tree root,int insertData)
{
    if (root == NULL)
        return;
    Tree* copyRoot = &root;
    TreeNode* newTreeNode = new TreeNode;
    newTreeNode->data = insertData;
    newTreeNode->treeLeft = NULL;
    newTreeNode->treeRight = NULL;

    while(copyRoot != NULL)
    {
        if (insertData < (*copyRoot)->data)
        {
            if ((*copyRoot)->treeLeft != NULL)
            {
                copyRoot = &(*copyRoot)->treeLeft;
            }
            else
            {
                (*copyRoot)->treeLeft = newTreeNode;
                return;
            }
        }
        else
        {
            if ((*copyRoot)->treeRight != NULL)
            {
                copyRoot = &(*copyRoot)->treeRight;
            }
            else
            {
                (*copyRoot)->treeRight = newTreeNode;
                return;
            }
        }
    }
}

void printTreeNode(Tree root)
{
    TreeNode rootNode = *root;
    queue<TreeNode> treeNodeQueue;
    treeNodeQueue.push(rootNode);
    while(!treeNodeQueue.empty())
    {
        TreeNode popTreeNode = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (popTreeNode.treeLeft != NULL)
            treeNodeQueue.push(*popTreeNode.treeLeft);
        if (popTreeNode.treeRight != NULL)
            treeNodeQueue.push(*popTreeNode.treeRight);
        cout << popTreeNode.data << " ";
    }
}

void printInorderTreeNode(Tree root)
{
    if (root == NULL)
        return;
    printInorderTreeNode(root->treeLeft);
    cout << root->data << " ";
    printInorderTreeNode(root->treeRight);
}

int main()
{
    Tree root = createTree(10);
    for (int i = 0 ; i < 4 ; i++)
    {
        int num;
        cin >> num;
        insertTreeNode(root,num);
    }
    //printTreeNode(root);
    printInorderTreeNode(root);

    system("pause");
    return 0;
}
