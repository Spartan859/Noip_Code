#include<iostream>
using namespace std;
int readint() {
	int num = 0;       // �洢��ȡ�������� 
	int negative = 0;  // ������־ 
	char c;            // �洢��ǰ��ȡ�����ַ� 
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


