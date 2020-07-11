#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int sum = 0;
	while (i <= 100) {
		sum += i;
		i += 2;
	} 
	cout << sum << endl;
	return 0;
} 
