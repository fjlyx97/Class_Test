#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

using namespace std;

class A
{
private:
    list<int> myData;
    std::mutex my_mutex;
    std::mutex my_mutex1;
public:
    A() { cout << "construct A " << endl;}
    A(const A* mA) { cout << "copy construct A " << endl;}

    void pushData()
    {
        cout << "Enter pushData " << endl;
        for (int i = 0 ; i < 100000 ; i++)
        {
            cout << "Push data : " << i << endl;
            std::unique_lock<std::mutex> sbguard(my_mutex);
            std::mutex* ptx = sbguard.release();
            ptx->unlock();
            myData.push_back(i);
        }
        cout << "End pushData " << endl;
    }
    void popData()
    {
        cout << "Enter popData " << endl;
        for (int i = 0 ; i < 100000 ; i++)
        {
            if(!myData.empty())
            {
                cout << "Pop data : " << myData.front() << endl;
                std::unique_lock<std::mutex> sbguard1(my_mutex1,std::defer_lock);
                sbguard1.lock();
                myData.pop_front();
            }
        }
        cout << "End popData " << endl;
    }
};

int main()
{
    A tempA;
    std::thread thread1(&A::pushData,&tempA);
    std::thread thread2(&A::popData,&tempA);
    thread1.join();
    thread2.join();
    
    return 0;
}