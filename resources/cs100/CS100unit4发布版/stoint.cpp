#include <iostream>
#include <string>
#include <cstdlib>//��׼library 
#include <sstream>
using namespace std;

int main()
{
	string s = "12345";
	cout << "The string is " << s << endl;
	cout << "The length of s: " << s.size() << endl; 
	int n;
	n = atoi(s.c_str());//��sת��Ϊ����n 
	cout << n << endl;
	return 0;
}



