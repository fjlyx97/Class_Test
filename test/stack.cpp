#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

class Calculator
{
private:
    //������ʽ
    string mExpression;
    //�����׺���ʽ
    stack<char> mStack;
    //���淴ת�ĺ�׺���ʽ
    stack<char> reverseStack;
    //������;�ķ���
    stack<char> symbolStack;

private:
    //����׺���ʽ��Ϊ��׺���ʽ
    bool updateExpression()
    {
        for (int i = 0 ; i < this->mExpression.length() ; i++)
        {
            //���������ֱ��ѹ���׺���ʽջ
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
                //�����ȼ�����ջ��Ԫ�أ���ջ��Ԫ�س�ջ������ѹ��
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
        //��תջ
        while(!this->mStack.empty())
        {
            this->reverseStack.push(this->mStack.top());
            this->mStack.pop();
        }
        /* ���Դ���
        //�������벻ͬ��������������
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
        cout << "Ҫ����ı��ʽ�ǣ�" << this->mExpression << endl;
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
    cout << "���Ϊ: " << result << endl;

    system("pause");
    return 0;
}