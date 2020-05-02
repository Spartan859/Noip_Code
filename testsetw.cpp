#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << setw(3) << 1 << 1234 << endl;
	cout << 1234 << setw(7) << 1234 << 12345 << endl;
	cout << 1234 << setw(3) << 12345 << endl;
	cout << 1234 << setw(4) << 123456 << 12 << setw(5) << 123 << endl;
	return 0;
}
