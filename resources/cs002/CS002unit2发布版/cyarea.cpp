#include <iostream>
using namespace std;

int main(){
	double r, h, area;
	double PI=3.14159265358979323846;
	cin >> r >> h;
	area = 2 * PI * r * r + 2 * PI * r * h;
	cout << area << endl;
} 
