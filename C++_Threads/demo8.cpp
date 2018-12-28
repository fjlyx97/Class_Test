#include <iostream>
#include <thread>
#include <future>
#include <mutex>
using namespace std;
int mythread(int num) //线程入口函数
{
    cout << "mythread start " << "Thread id::" << std::this_thread::get_id() << endl;
    cout << "mythread num : " << num << endl;
    std::chrono::milliseconds dura(5000); //休息五秒
    std::this_thread::sleep_for(dura);
    cout << "mythread end" << endl;
    return 5;
}
int main()
{
    //cout << "main : " << std::this_thread::get_id() << endl;
    std::packaged_task<int(int)> mypt(mythread);
    std::thread t1(std::ref(mypt),1);
    t1.join();
    
    std::future<int> result = mypt.get_future();
    std:shared_future<int> result_s(std::move(result));
    cout << result_s.get() << endl;
    cout << result_s.get() << endl;

    system("pause");
    return 0;
}