#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, first, last, fullname;
	cout << "Please input your name" << endl;
	cin >> name;
	cout << "You are " << name << endl;
	cout << "Please input your name, i.e. James Bond" << endl;
	cin >> first;
	cin >> last;
	cin.get();  //¶ÁÈ¡»»ÐÐ·û 
	cout << "You are " << first << " " << last << endl;
	cout << "Please input your name, i.e. James Bond" << endl;
	getline(cin, fullname);
	cout << "You are " << fullname << endl;
	return 0;
}


