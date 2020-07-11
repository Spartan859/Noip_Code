#include<iostream>
using namespace std;
long long a,b,temp;
long long gcd(long long x,long long y){
	while(x%y!=0){
		temp=x%y;
		x=y;
		y=temp;
	}
	cout<<y;
}
int main(){
    cin>>a>>b;
	gcd(a,b);
	return 0;	
}
