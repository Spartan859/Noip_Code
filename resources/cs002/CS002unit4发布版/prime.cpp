#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	while (true) {
		int n;
		bool isPrime = true;
		cout << "Enter -1 to quit the program." << endl;
		cout << "Please input a number: ";
		cin >> n;
		if (n == -1) break;
		for (int i=2; i*i<=n; ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			cout << n << " is a prime number." << endl;
		else
			cout << n << " is not a prime number." << endl;
	} 
	return 0;
} 
