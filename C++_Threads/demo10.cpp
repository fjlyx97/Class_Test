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
    //std::mutex my_mutex;
    std::recursive_mutex my_mutex;
public:
    void pushData()
    {
        cout << "Enter pushData " << endl;
        for (int i = 0 ; i < 1000 ; i++)
        {
            my_mutex.lock();
            cout << "Push : " << i << endl;
            myData.push_back(i);
            my_mutex.unlock();
        }
        cout << "End pushData " << endl;
    }
    void popData()
    {
        cout << "Enter popData " << endl;
        for (int i = 0 ; i < 1000 ; i++)
        {
            if(!myData.empty())
            {
                my_mutex.lock();
                myData.pop_front();
                cout << "Pop : " << i << endl;
                my_mutex.unlock();
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