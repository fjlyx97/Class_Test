#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
using namespace std;
mutex mymutex;
int num = 0;
void fun()
{
    mymutex.lock();
    for ( int i = 1 ; i <= 10 ; i++)
    {
        cout << "hello world" << endl;
        Sleep(1000);
        cout << num << endl;
    }
    mymutex.unlock();
}

void fun1()
{
    for (int i = 1 ; i < 10 ; i++)
    {
        num++;
        Sleep(1000);
    }
}
int main()
{
    thread thread1 = thread(fun);
    thread1.detach();
    thread thread2 = thread(fun1);
    thread2.detach();

    system("pause");
    return 0;
}