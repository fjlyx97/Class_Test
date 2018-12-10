#include <iostream>
#include <thread>
#include <string>
using namespace std;
void myprint(const int &i,const string& pmybuf)
{
    //不推荐用引用传参，绝对不要用指针
    cout << i << endl; //分析认为,i的地址和main函数中i地址不相同，因此i的值是安全的（复制的）
    cout << pmybuf << endl; //pmybuf指向的是main函数中的mybuf，不安全
    return;
}
int main()
{
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test!";
    //thread myobj(myprint,mvar,mybuf); //存在mybuf被回收了，才开始复制
    //正确写法
    thread myobj(myprint,mvar,string(mybuf)); 
    myobj.detach();
    cout << "I Love China" << endl;

    return 0;
}