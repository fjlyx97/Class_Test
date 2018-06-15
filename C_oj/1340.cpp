#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <functional>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int difficult;
    priority_queue<int, vector<int> , less<int> > questions;
    set<int> book_questions;
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> difficult;
        questions.push(difficult);
        book_questions.insert(difficult);
    }
    while(true)
    {
        int temp_num = questions.top();
        while(temp_num > 0 && book_questions.count(temp_num) == 1)
        {
            temp_num /= 2;
        }
        if (!temp_num)
        {
            break;
        }
        questions.pop();
        questions.push(temp_num);
        book_questions.insert(temp_num);
    }
    cout << questions.top() << endl;
    system("pause");
    return 0;
}