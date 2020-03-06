#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <deque>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> ans;
        if (A.empty())
            return ans;
        vector<int> head , tail;
        int t = 1;
        for (int i = 0 ; i < A.size() ; i++)
        {
            t *= A[i];
            head.push_back(t);
        }
        t = 1;
        for (int i = A.size()-1 ; i >= 0 ; i--)
        {
            t *= A[i];
            tail.push_back(t);
        }
        for (auto t : head)
            cout << t << " ";
        cout << endl;
        for (auto t : tail)
            cout << t << " ";
        for (int i = 0 ; i < A.size() ; i++)
        {
            int left = i-1;
            int right = (A.size()-1)-i-1;
            if (left < 0)
            {
                ans.push_back(tail[tail.size()-2]);
                continue;
            }
            if (right < 0)
            {
                ans.push_back(head[head.size()-2]);
                continue;
            }
            ans.push_back(head[left]*head[right]);
        }
        return ans;
    }
};
int main()
{
    vector<int> t = {1,2,3,4,5};
    Solution s;
    for (auto a :s.multiply(t))
        cout << a << " ";
    cout << endl;
    //vector<vector<int> > t;
    //vector<int> ans = {2,3,4,2,6,2,5,1};
    //Solution s;
    //for (auto t : vector<int>(s.maxInWindows(ans,3)))
    //    cout << t << " ";
    cout << endl;
    //TreeNode *pHead = new TreeNode(8);
    //TreeNode *pHead1 = new TreeNode(6);
    //TreeNode *pHead2 = new TreeNode(10);
    //TreeNode *pHead3 = new TreeNode(5);
    //TreeNode *pHead4 = new TreeNode(7);
    //TreeNode *pHead5 = new TreeNode(9);
    //TreeNode *pHead6 = new TreeNode(11);
    //pHead->left = pHead1;
    //pHead->right = pHead2;
    //pHead1->left = pHead3;
    //pHead1->right = pHead4;
    //pHead2->left = pHead5;
    //pHead2->right = pHead6;
    //t = s.Print(pHead);
    //for (auto t1 : t)
    //{
    //    for (auto t2 : t1)
    //        cout << t2 << " ";
    //    cout << endl;
    //}
    //cout << endl;

    //char* t = s.Serialize(pHead);
    //cout << t << endl;
    //TreeNode *root = s.Deserialize(t);
    //cout << root << endl;
    //TreeNode *pNode1 = new TreeNode(2);
    //TreeNode *pNode2 = new TreeNode(4);
    //TreeNode *pNode3 = new TreeNode(7);
    //pNode1->left = pNode2;
    //pNode2->left = pNode3;
    //cout << s.HasSubtree(pHead,pHead1) << endl;
    //cout << s.HasSubtree(pHead,pNode1) << endl;
    //cout << s.HasSubtree(nullptr,pHead4) << endl;
    //cout << s.HasSubtree(pHead,nullptr) << endl;
    //cout << s.HasSubtree(nullptr,nullptr) << endl;

    //Solution s;
    //ListNode* pHead = new ListNode(2);
    //ListNode* pHead1 = new ListNode(2);
    //ListNode* pHead2 = new ListNode(3);
    //ListNode* pHead3 = new ListNode(1);
    //ListNode* pHead4 = new ListNode(1);
    //ListNode* pHead5 = new ListNode(3);
    //ListNode* pHead6 = new ListNode(5);
    //pHead->next = pHead1;
    //pHead1->next = pHead2;
    //pHead2->next = pHead3;
    //pHead3->next = pHead4;
    //pHead4->next = pHead5;
    //pHead5->next = pHead6;
    //pHead6->next = pHead4;
    system("pause");
    return 0;
}
