#include <iostream>
using namespace std;

int main()
{
	int n, a[20]; //数组a保存n的各位数字 
	int l=0; //数字长度 
	cin >> n;
	// 当n至少为2位数，执行循环 
	while (n >= 10) {
		// 取个位数字，并保存 
		int r;
		r = n % 10;
		a[l++] = r;
		// n减少一位数字
		n /= 10;
	}
	// 保存最后一位数字 
	a[l] = n;
	// 依次输出n的各位数字 
	for (int i=l; i >= 0; --i) {
		cout << a[i] << " ";
	}
	return 0;
}
