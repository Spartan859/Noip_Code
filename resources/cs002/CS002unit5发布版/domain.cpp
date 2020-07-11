#include <iostream>
using namespace std;

int a, b;  //全局变量 
 
int main()
{
	int n;  //局部变量 
	cin >> n;
	while (n > 0) {
		int sum;  //局部变量 
		cin >> a >> b;
		sum = a + b;
		cout << sum << endl;
		n--;
	} 
	cout << a + b << endl;
}


