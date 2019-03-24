#include <iostream>
using namespace std;
template<typename ElemType>
struct queue
{
    ElemType* num;
    ElemType front;
    ElemType tail;
    int size;
    //初始化必要参数，头指针以及尾指针为0，队列为空
    queue(int mSize = 10) : size(mSize) , num(new ElemType[mSize]) , front(0) , tail(0) {}
    ~queue()
    {
        delete[] this->num;
    }
    bool push(ElemType insertNum)
    {
        if ((tail+1)%size == front)
            return false;
        this->num[tail] = insertNum;
        tail = (tail+1)%size;
        return true;
    }
    bool pop()
    {
        if (front == tail)
            return false;
        front = (front+1)%size;
        return true;
    }
    bool printQueue()
    {
        int mFront = this->front;
        while (mFront != this->tail)
        {
            cout << this->num[mFront] << " ";
            mFront = (mFront+1)%size;
        }
        cout << endl;
        return true;
    }
};
int main()
{
    queue<int> mQueue(20);
    for (int i = 0 ; i < 10 ; i++)
        mQueue.push(i);
    mQueue.printQueue();
    //循环左移
    for (int i = 0 ; i < 5 ; i++)
    {
        int frontNum = mQueue.front;
        mQueue.pop();
        mQueue.push(frontNum);
    }
    mQueue.printQueue();

    return 0;
}