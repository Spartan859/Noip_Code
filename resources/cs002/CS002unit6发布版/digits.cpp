#include <iostream>
using namespace std;

int main()
{
	int n, a[20]; //����a����n�ĸ�λ���� 
	int l=0; //���ֳ��� 
	cin >> n;
	// ��n����Ϊ2λ����ִ��ѭ�� 
	while (n >= 10) {
		// ȡ��λ���֣������� 
		int r;
		r = n % 10;
		a[l++] = r;
		// n����һλ����
		n /= 10;
	}
	// �������һλ���� 
	a[l] = n;
	// �������n�ĸ�λ���� 
	for (int i=l; i >= 0; --i) {
		cout << a[i] << " ";
	}
	return 0;
}
