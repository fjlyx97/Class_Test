#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex rescource_mutex;
std::once_flag g_flag;

class MyCAS
{
    static void createInstance()
    {
        m_instance = new MyCAS();
        static CGarhuishou cl; //静态对象生命周期一直到程序退出
    }
private:
    MyCAS()  //私有化了构造函数
    {
    } 
private:
    static MyCAS *m_instance; //静态成员变量

public:
    static MyCAS* GetInstance()
    {
        std::call_once(g_flag,createInstance);
        cout << "CallOnce over" << endl;
        return m_instance;
    }

    class CGarhuishou //类中套类，用来释放对象
    {
        public:
            ~CGarhuishou()
            {
                if (MyCAS::m_instance)
                {
                    delete MyCAS::m_instance;
                    MyCAS::m_instance = NULL;
                }
            }
    };

    void func()
    {
        cout << "Test " << endl;
    }
};
MyCAS* MyCAS::m_instance = NULL;

void initThread()
{
    cout << "In" << endl;
    MyCAS::GetInstance();
    cout << "Out" << endl;
    return;
}

int main()
{
    cout << num << endl;
    std::thread t1(initThread);
    std::thread t2(initThread);

    t1.join();
    t2.join();
    system("pause");
    return 0;
}