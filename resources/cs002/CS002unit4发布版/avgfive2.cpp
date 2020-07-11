#include <iostream>
using namespace std;

int main()
{
	int times = 5;
	double sum = 0;
	for (int i=1; i <= times; ++i) {
		int n;
		cin >> n;
		sum += n;
	}
	cout << "The average is " << sum / 5 << endl;
	return 0;
} 
