#include<iostream>
using namespace std;
long long x,y;
long long gcd(long long a, long long b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a,b)*b; 
}
int main(){
	cin>>x>>y;
	cout<<lcm(x,y); 
	return 0;
}




