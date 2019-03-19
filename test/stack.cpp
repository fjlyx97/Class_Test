#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

class Calculator
{
private:
    //储存表达式
    string mExpression;
    //储存后缀表达式
    stack<char> mStack;
    //储存反转的后缀表达式
    stack<char> reverseStack;
    //储存中途的符号
    stack<char> symbolStack;

private:
    //将中缀表达式变为后缀表达式
    bool updateExpression()
    {
        for (int i = 0 ; i < this->mExpression.length() ; i++)
        {
            //如果是数字直接压入后缀表达式栈
            char tempChar = this->mExpression.at(i);
            if ( '0' <= tempChar && tempChar <= '9')
            {
                mStack.push(tempChar);
                for (int j = i+1 ; j < this->mExpression.length() ; j++)
                {
                    tempChar = this->mExpression.at(j);
                    if ( '0' <= tempChar && tempChar <= '9')
                        mStack.push(tempChar);
                    else
                    {
                        mStack.push(' ');
                        i = j-1;
                        break;
                    }
                }
            }
            else
            {
                char topChar = '\0';
                if (!symbolStack.empty())
                    topChar = symbolStack.top();
                //若优先级低于栈顶元素，则栈顶元素出栈，自身压入
                if (tempChar == '+')
                {
                    while (true)
                    {
                        if (this->symbolStack.empty())
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                        topChar = this->symbolStack.top();
                        if (topChar == '*' || topChar == '/' || topChar == '-' || topChar == '+')
                        {
                            this->mStack.push(this->symbolStack.top());
                            this->mStack.push(' ');
                            this->symbolStack.pop();
                        }
                        else
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                    }
                }
                if (tempChar == '-')
                {
                    while (true)
                    {
                        if (this->symbolStack.empty())
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                        topChar = this->symbolStack.top();
                        if (topChar == '*' || topChar == '/' || topChar == '+' || topChar == '-')
                        {
                            this->mStack.push(this->symbolStack.top());
                            this->mStack.push(' ');
                            this->symbolStack.pop();
                        }
                        else
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                    }
                }
                if (tempChar == '*')
                {
                    while (true)
                    {
                        if (this->symbolStack.empty())
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                        topChar = this->symbolStack.top();
                        if (topChar == '/' || topChar == '*')
                        {
                            this->mStack.push(this->symbolStack.top());
                            this->mStack.push(' ');
                            this->symbolStack.pop();
                        }
                        else
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                    }
                }
                if (tempChar == '/')
                {
                    while (true)
                    {
                        if (this->symbolStack.empty())
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                        topChar = this->symbolStack.top();
                        if (topChar == '*' || topChar == '/')
                        {
                            this->mStack.push(this->symbolStack.top());
                            this->mStack.push(' ');
                            this->symbolStack.pop();
                        }
                        else
                        {
                            this->symbolStack.push(tempChar);
                            break;
                        }
                    }
                }
                if (tempChar == '(')
                    this->symbolStack.push(tempChar);
                if (tempChar == ')')
                {
                    while (this->symbolStack.top() != '(')
                    {
                        this->mStack.push(this->symbolStack.top());
                        this->mStack.push(' ');
                        this->symbolStack.pop();
                    }
                    this->symbolStack.pop();
                }
            }
        }
        while(!this->symbolStack.empty())
        {
            this->mStack.push(' ');
            this->mStack.push(this->symbolStack.top());
            this->symbolStack.pop();
        }
        //反转栈
        while(!this->mStack.empty())
        {
            this->reverseStack.push(this->mStack.top());
            this->mStack.pop();
        }
        /* 调试代码
        //拷贝代码不同编译器出现问题
        //memcpy(&this->mStack,&reverseStack,sizeof(reverseStack));
        while (!this->mStack.empty())
        {
            cout << this->mStack.top();
            this->mStack.pop();
        }
        exit(0);
        */
        return true;
    }

public:
    Calculator(string inputExpression) : mExpression(inputExpression)
    {
        cout << "要计算的表达式是：" << this->mExpression << endl;
        this->updateExpression();
    }

    double getResult()
    {
        stack<double> saveNum;
        
        while(!this->reverseStack.empty())
        {
            char topChar = this->reverseStack.top();
            //cout << topChar;
            if (topChar == ' ')
            {
                this->reverseStack.pop();
                continue;
            }
            if (topChar <= '9' && '0' <= topChar)
            {
                int tempSaveNum = topChar-'0';
                this->reverseStack.pop();
                while(!this->reverseStack.empty())
                {
                    topChar = this->reverseStack.top();
                    if (topChar <= '9' && topChar >= '0')
                    {
                        tempSaveNum = tempSaveNum * 10 + (topChar-'0');
                        this->reverseStack.pop();
                    }
                    else
                    {
                        saveNum.push(tempSaveNum);
                        this->reverseStack.pop();
                        break;
                    }
                }
            }
            else
            {
                double num1 = saveNum.top();
                saveNum.pop();
                double num2 = saveNum.top();
                saveNum.pop();
                if (topChar == '+')
                    saveNum.push(num2+num1);
                else if (topChar == '-')
                    saveNum.push(num2-num1);
                else if (topChar == '*')
                    saveNum.push(num2*num1);
                else if (topChar == '/')
                    saveNum.push((double)num2/num1);
                this->reverseStack.pop();
            }
        }
        return saveNum.top();
    }
};

int main()
{
    string inputExpression("(9+8*7/6+3)*5/3");
    Calculator mCalmulator(inputExpression);
    double result = mCalmulator.getResult();
    cout << "结果为: " << result << endl;

    system("pause");
    return 0;
}