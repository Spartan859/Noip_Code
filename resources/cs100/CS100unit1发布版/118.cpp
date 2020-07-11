#include<iostream>
using namespace std;
long long gcd(int x,int y){
	long long tmp;
	while (tmp=x%y){
		x=y;
		y=tmp;
	}
	return y;
}	
int main(){
	long long a,b,LCM;
	cin>>a>>b;
	LCM=a*b/gcd(a,b); 
	cout<<LCM;
	return 0;
}


