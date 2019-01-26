#include<bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cout << "Please input a:";
	cin >> a;
	cout << "Please input b:";
	cin >> b;
	if (a > b) cout << a << ' ' << b<<endl;
	else if (a < b) cout << b << ' ' << a << endl;
	else if (a == b) cout << "What a coincidence!" << endl;
	return 0;
}
