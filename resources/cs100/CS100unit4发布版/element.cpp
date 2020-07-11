#include <iostream>
#include <string>
using namespace std;

int main()
{
	string l = "123456789";
	cout << l << endl;
	string title = "My string.";
	cout << title << endl;
	cout << title.size() << endl;
	for (int i=0; i < title.size(); ++i) {
		cout << title[i] << " ";
	}
	return 0;
}


