#include<iostream>
using namespace std;

int readint() {
	int num = 0;       // �洢��ȡ�������� 
	int negative = 0;  // ������־ 
	char c;            // �洢��ǰ��ȡ�����ַ� 
	c = cin.get();
	while ((c < '0' || c > '9') && c != '-')
		c = cin.get();
	if (c == '-')
		negative = 1;
	else
		num=c-'0';
	c = cin.get();
	while ((c > '0' || c < '9') && c != '-') {
		num=num*10+c-48;
		c = cin.get();
	}
	if (negative == 1)
		num*=-1;
	return num;
} 

int main() {
	int a, b;
	a = readint();
	b = readint();
	cout << a << endl << b << endl;
	return 0;
}
