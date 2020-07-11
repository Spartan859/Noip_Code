#include <iostream>
#include <string>
using namespace std;

int main()
{
	string fullname;
	cout << "Please input your full name." << endl;
	getline(cin, fullname);//整行读取，保存在fullname中 
	cout << "Your name is " << fullname << endl;
	return 0;
}


