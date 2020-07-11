#include <iostream>
#include <string>
#include <cstdlib>//标准library 
#include <sstream>
using namespace std;

int main()
{
	string s = "12345";
	cout << "The string is " << s << endl;
	cout << "The length of s: " << s.size() << endl; 
	int n;
	n = atoi(s.c_str());//把s转换为整数n 
	cout << n << endl;
	return 0;
}



