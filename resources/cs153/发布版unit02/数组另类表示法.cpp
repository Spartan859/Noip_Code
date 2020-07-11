#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
int x[SIZE]={233,666,88,1,24,7};
int main() {
	cout<<x[3]<<endl;
	cout<<*x<<endl;
	cout<<*(x+2)<<endl;
	cout<<x+2<<endl;
	cout<<(x+4)[1]<<endl;
	return 0;
}

