#include<iostream>
using namespace std;
int n;
long long fbnq(long long m){
	if(m==0) return 0;
	if(m==1) return 1;
	else return fbnq(m-1)+fbnq(m-2);
}
int main(){
	cin>>n;
	cout<<fbnq(n);
	return 0;
}
