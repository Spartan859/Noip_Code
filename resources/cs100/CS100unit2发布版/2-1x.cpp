#include<iostream>
using namespace std;
long long s(long long x){
	if(x==0) return 0;
	return s(x-1)+x*x;
}
int main(){
	long long n;
	cin>>n;
	cout<<s(n);
}
