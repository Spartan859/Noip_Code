#include<iostream>
using namespace std;
long long f(int x){
	if(x==0) return 1;
	else return f(x-1)*x;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}
