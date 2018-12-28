#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
std::atomic<int> g_count(0);
//int g_count = 0;
int mythread()
{
    for (int i = 0 ; i < 10000000 ; i++)
    {
        g_count++;
    }
    return g_count;
}
using namespace std;
int main()
{
    std::future<int> result = std::async(mythread);
    cout << result.get() << endl;

    system("pause");
    return 0;
}