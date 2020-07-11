#include <iostream>
using namespace std;

int main()
{
	int times = 5;
	double sum = 0;
	while (times > 0) {
		int n;
		cin >> n;
		sum += n;
		times--;
	}
	cout << "The average is " << sum / 5 << endl;
	return 0;
} 
