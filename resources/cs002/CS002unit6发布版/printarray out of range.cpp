#include <iostream>
using namespace std;

int main() {
	int a[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
	// 越界
	for (int i=0; i <=10; ++i) {
		cout << a[i] << " ";
	}
	cout<<endl;
	// 越界
	for (int i=10; i >=0; i--) {
		cout << a[i] << " ";
	}
	cout<<endl;
	return 0;
}


