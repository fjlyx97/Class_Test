#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Calculator
{
private:
    //������ʽ
    string mExpression;
    //�����׺���ʽ
    stack<char> mStack;
    //������;�ķ���
    stack<char> symbolStack;

private:
    bool updateExpression()
    {
        for (int i = 0 ; i < this->mExpression.length() ; i++)
        {
            //���������ֱ��ѹ���׺���ʽջ
            char tempChar = this->mExpression.at(i);
            if ( '0' <= tempChar && tempChar <= '9')
                mStack.push(tempChar);
            else
            {
                char topChar = '\0';
                if (!symbolStack.empty())
                    topChar = symbolStack.top();
                //�����ȼ�����ջ��Ԫ�أ���ջ��Ԫ�س�ջ������ѹ��
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
        cout << "Ҫ����ı��ʽ�ǣ�" << this->mExpression << endl;
        this->updateExpression();
        while (!this->mStack.empty())
        {
            cout << this->mStack.top();
            this->mStack.pop();
        }
        cout << endl;
    }

    //����׺���ʽ��Ϊ��׺���ʽ
    
};

int main()
{
    string inputExpression("9+(3-1)*3+10/2");
    Calculator mCalmulator(inputExpression);
    system("pause");
    return 0;
}