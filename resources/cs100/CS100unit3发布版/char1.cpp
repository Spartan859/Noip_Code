#include <iostream>

using namespace std;

int main()
{
	char h[] = "Hello!";
	char *p = h;
	int i;
	while (*p) {
		cout << "The ASCII code of " << *p << " is ";
		i = *p;
		cout << i << endl;
		p++;
	}
	char c;
	for (i=33; i < 125; i++) {
		c = i;
		cout << c;
	}

}
