#include <iostream>

//包含thread头文件
#include <thread>
//创建一个函数
void myprint()
{
    std::cout << "Thread begin.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    std::cout << "Thread end.." << std::endl;
    return;
}

int main()
{
    std::thread myobj(myprint);
    myobj.join();
    if (myobj.joinable())
    {
        std::cout << "1:joinable() == true" << std::endl;
    }
    else
    {
        std::cout << "2:joinable() == false" << std::endl;
    }
    std::cout << "I love China!" << std::endl;

    system("pause");
    return 0;
}