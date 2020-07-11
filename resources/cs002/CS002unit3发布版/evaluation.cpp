#include <iostream>
using namespace std;

int main()
{
	int score;
	cin >> score;
	if (score >=90)
		cout << "A" << endl;
	else if (score >= 75)
		cout << "B" << endl;
	else if (score >= 60)
		cout << "C" << endl;
	else if (score < 60)
		cout << "D" << endl;
	return 0;
} 
