#include<iostream>
using namespace std;
long long n;
int main(){
	cin>>n;
	if(n<50) cout<<n*10;
	if(n>=50&&n<100) cout<<n*10*0.8;
	if(n>=100) cout<<n*10*0.7;
	return 0;
}
