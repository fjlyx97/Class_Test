#include <iostream>
using namespace std;
template<typename T>
class CPeople
{
public:
    int age;
    int height;
    CPeople(T a,T b)
    {
        age = a;
        height = b;
    }
    void show()
    {
        cout << this->age << '\t' << this->height << endl;
    }

};
int main()
{
    CPeople<int> st(15,180);
    st.show();
    system("pause");
    return 0;
}