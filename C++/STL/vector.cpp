#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> var(5,12); //5个12.
    vector<char> var1(5,'a');
    vector<int> var2(var); //相同类型可以直接初始化，否则不行
    //vector<int>::iterator ite = var1.begin(); //返回头
    //vector<int>::iterator ite1 = var1.end(); //返回尾

//    for (int i = 0 ; i < 5 ; i++)
//    {
//        cout << var1[i] << endl;
//    }

    vector<int> test(5);
    cout << test.capacity() << endl;
    cout << test.size() << endl;
    test.reserve(10);
    test.resize(7);
    cout << test.capacity() << endl; //查看容量
    cout << test.size() << endl; //查看有效个数
    cout << test.empty() << endl; //有1无0


    system("pause");
    return 0;
}