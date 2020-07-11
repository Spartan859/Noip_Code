#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "There are two needles in this haystack with needles.";
	string str2("needle");
	int found = str.find(str2);
	if (found != string::npos)
		cout << "first needle found at: " << found << endl;
	found = str.find("needles are small", found+1, 6);
	if (found != string::npos)
		cout << "second needle found at: " << found << endl;
	found = str.find("haystack");
	if (found != string::npos)
		cout << "haystack? also found at:" << found << endl;
	found = str.find('.');
	if (found != string::npos)
		cout << "Period found at: " << found << endl; 
	return 0;	
} 
