#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int n;
	string s;
	ostringstream oss;//output string stream¼ò³Æoss 
	cout << "Enter a number: ";
	cin >> n;
	oss << n;
	s = oss.str();
	cout << s << endl; 
	return 0; 
}


