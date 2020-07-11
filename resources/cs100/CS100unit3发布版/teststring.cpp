#include <iostream>
#include <string>
using namespace std;

int main()
{
string s = "Tom";
string s2 = "first";
s.insert(0,"My name "); 
s.insert(3,s2); 
cout << s << endl;
	return 0;	
} 
