#include <iostream>
using namespace std;

int a, b;  //ȫ�ֱ��� 
 
int main()
{
	int n;  //�ֲ����� 
	cin >> n;
	while (n > 0) {
		int sum;  //�ֲ����� 
		cin >> a >> b;
		sum = a + b;
		cout << sum << endl;
		n--;
	} 
	cout << a + b << endl;
}


