#include<iostream>
using namespace std;
int readint() {
	int num = 0;       // 存储读取到的整数 
	int negative = 0;  // 负数标志 
	char c;            // 存储当前读取到的字符 
	c = cin.get();
	while ((c < '0' || c > '9') && c != '-')
		c = ____(1)____;
	if (c == '-')
		negative = 1;
	else
		____(2)____;
	c = cin.get();
	while (____(3)____) {
		____(4)_____;
		c = cin.get();
	}
	if (negative == 1)
		____(5)____;
	return num;
} 
int main() {
	int a, b;
	a = readint();
	b = readint();
	cout << a << endl << b << endl;
	return 0;
}


