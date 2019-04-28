#include <iostream>
using namespace std;

void F(int a) {
	cout << a << endl;
}

template<class A>
void G(A &&a) {
	return F(std::forward<A>(a));  
}

int main() {
	G(5);

	system("pause");
    return 0;
}