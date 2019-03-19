#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Calculator
{
private:
    //储存表达式
    string mExpression;
    //储存后缀表达式
    stack<char> mStack;
    //储存中途的符号
    stack<char> symbolStack;

private:
    bool updateExpression()
    {
        for (int i = 0 ; i < this->mExpression.length() ; i++)
        {
            //如果是数字直接压入后缀表达式栈
            char tempChar = this->mExpression.at(i);
            if ( '0' <= tempChar && tempChar <= '9')
                mStack.push(tempChar);
            else
            {
                char topChar = '\0';
                if (!symbolStack.empty())
                    topChar = symbolStack.top();
                //若优先级低于栈顶元素，则栈顶元素出栈，自身压入
                if (tempChar == '+')
                {
                    if (topChar == '*' || topChar == '/' || topChar == '-' || topChar == '+')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->symbolStack.pop();
                    }
                    this->symbolStack.push(tempChar);
                }
                if (tempChar == '-')
                {
                    if (topChar == '*' || topChar == '/' || topChar == '+' || topChar == '-')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->symbolStack.pop();
                    }
                    this->symbolStack.push(tempChar);
                }
                if (tempChar == '*')
                {
                    if (topChar == '/' || topChar == '*')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->symbolStack.pop();
                    }
                    this->symbolStack.push(tempChar);
                }
                if (tempChar == '/')
                {
                    if (topChar == '*' || topChar == '/')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->symbolStack.pop();
                    }
                    this->symbolStack.push(tempChar);
                }
                if (tempChar == '(')
                    this->symbolStack.push(tempChar);
                if (tempChar == ')')
                {
                    while (this->symbolStack.top() != '(')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->symbolStack.pop();
                    }
                    this->symbolStack.pop();
                }
            }
        }
        while(!this->symbolStack.empty())
        {
            this->mStack.push(this->symbolStack.top());
            this->symbolStack.pop();
        }
        return true;
    }

public:
    Calculator(string inputExpression) : mExpression(inputExpression)
    {
        cout << "要计算的表达式是：" << this->mExpression << endl;
        this->updateExpression();
        while (!this->mStack.empty())
        {
            cout << this->mStack.top();
            this->mStack.pop();
        }
        cout << endl;
    }

    //将中缀表达式变为后缀表达式
    
};

int main()
{
    string inputExpression("9+(3-1)*3+10/2");
    Calculator mCalmulator(inputExpression);
    system("pause");
    return 0;
}