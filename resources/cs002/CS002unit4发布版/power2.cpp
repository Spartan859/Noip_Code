#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int prod = 1;
	while (prod <= 10000000) {
		prod *= 2;
		i++;
	}
	cout << i << endl;
	return 0;
} 


