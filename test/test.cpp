// Stack.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define IF 1
#define ELSE 2
template<typename T>
class Stack
{
public:
    Stack(int capcity = 100000);
    ~Stack();
    void ClearStack();
    bool IsEmpty();
    bool IsFull();
    int StackLength();
    T GetTop();
    void Push(T e);
    void Pop();
private:
    T* elemArray;
    int top;
    int capcity;
};

template <typename T>
Stack<T>::Stack(int capcity)
{
    if (capcity <= 0)
    {
        return;
    }
    this->capcity = capcity;
    top = 0;
    elemArray = new T[capcity];
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] elemArray;
}

template<typename T>
void Stack<T>::ClearStack()
{
    top = 0;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
    return (top == 0);
}

template<typename T>
bool Stack<T>::IsFull()
{
    return (top == capcity);
}

template<typename T>
int Stack<T>::StackLength()
{
    return top;
}

template <typename T>
T Stack<T>::GetTop()
{
    if (IsEmpty())
    {
        return -1;
    }
    return elemArray[top - 1];
}

template <typename T>
void Stack<T>::Push(T e)
{
    if (IsFull())
    {
        return;
    }
    elemArray[top] = e;
    top++;
}

template<typename T>
void Stack<T>::Pop()
{
    if (IsEmpty())
    {
        return;
    }
    top--;
}

//if->1 else->2
int IfOrElse(string inputString)
{
    if (!inputString.compare("if"))
        return 1;
    else if (!inputString.compare("else"))
        return 2;
    else return -1;
}

Stack<int> ifElseStack(100005);

int main()
{
    int inputNumber;
    int maxLength = 0;
    int tempLength = -1;
    string inputString;

    cin >> inputNumber;
    for (int i = 0; i<inputNumber; i++)
    {
        cin >> inputString;
        int stringToInt = IfOrElse(inputString); //if->1,else->2

        //Push Stack / Stack Empty Handle
        if (ifElseStack.IsEmpty())
        {
            ifElseStack.Push(stringToInt);
        }
        else if (stringToInt == IF)
        {
            ifElseStack.Push(stringToInt);
        }
        else if (stringToInt == ELSE && ifElseStack.GetTop() == IF)
        {
            ifElseStack.Pop();
            tempLength++;
        }
        else
        {
            ifElseStack.Push(stringToInt);
        }

        //maxLength
        if (ifElseStack.IsEmpty())
        {
            maxLength = maxLength > tempLength ? maxLength : tempLength;
            tempLength = -1;
        }
    }

    //error>NO,yes>maxLength
    ifElseStack.IsEmpty() ? cout << maxLength << endl : cout << "NO" << endl;

    return 0;
}