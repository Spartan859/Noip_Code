#include <iostream>
using namespace std;

int main() {
	int a[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
	// 使用for循环，从数组a[0]开始，一直访问到a[9] 
	for (int i=0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}


