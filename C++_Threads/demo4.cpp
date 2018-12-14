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
            std::lock(my_mutex,my_mutex1);
            std::lock_guard<std::mutex> sblock(my_mutex,std::adopt_lock);
            std::lock_guard<std::mutex> sblock1(my_mutex1,std::adopt_lock);

            cout << "Push data : " << i << endl;
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
                std::lock(my_mutex,my_mutex1);
                std::lock_guard<std::mutex> sblock(my_mutex,std::adopt_lock);
                std::lock_guard<std::mutex> sblock1(my_mutex1,std::adopt_lock);
                cout << "Pop data : " << myData.front() << endl;
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