#include <iostream>
using namespace std;

int main()
{
	int n, r;
	cin >> n;
	r = n % 2;
	if ( r == 0)
		cout << "even number" << endl;
	else
		cout << "odd number" << endl;
	return 0;	
} 
