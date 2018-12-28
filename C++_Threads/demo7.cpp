#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

class A
{
private:
    list<int> myData;
    std::mutex my_mutex1;
    std::condition_variable my_cond;
public:
    A() { cout << "construct A " << endl;}
    A(const A* mA) { cout << "copy construct A " << endl;}

    void pushData()
    {
        cout << "Enter pushData " << endl;
        for (int i = 0 ; i < 1000 ; i++)
        {
            std::unique_lock<std::mutex> sbguard(my_mutex1);
            cout << "Push data : " << i << endl;
            myData.push_back(i);
            my_cond.notify_all();  //尝试唤醒wait的线程
        }
        cout << "End pushData " << endl;
    }
    void popData()
    {
        cout << "Enter popData " << endl;
        while(true)
        {
            std::unique_lock<std::mutex> sbguard1(my_mutex1);
            //wait用来等一个东西
            //如果第二个参数（lambda）返回值为false,wait解锁互斥量，并堵塞到本行
            //如果返回值为true,wait()直接返回
            //堵塞到其他某个线程调用notify_one()成员函数为止
            //如果缺少第二个参数，结果就和lambda返回false一样
            //一旦被唤醒，会重新进行判断，如果返回true就继续往下执行
            my_cond.wait(sbguard1,[this]{
                if (!myData.empty())
                    return true;
                return false;
            });
            myData.pop_front();
            cout << "Thread id : " << std::thread::get_id << endl;
            cout << "Pop Data" << endl;
            sbguard1.unlock();
        }
        cout << "End popData " << endl;
    }
};

int main()
{
    A tempA;
    std::thread thread1(&A::pushData,&tempA);
    std::thread thread2(&A::popData,&tempA);
    std::thread thread3(&A::popData,&tempA);
    thread1.join();
    thread2.join();
    thread3.join();
    
    system("pause");
    return 0;
}