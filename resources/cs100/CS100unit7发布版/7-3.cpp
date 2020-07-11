#include<iostream>
using namespace std;
int l,i1,j1;
double a,b,temp=100000;
long long gcd(int x,int y){
	long long tmp;
	while (tmp=x%y){
		x=y;
		y=tmp;
	}
	return y;
}
int main(){
	cin>>a>>b>>l;
	for(double i=1;i<=l;i++)
	for(double j=1;j<=l;j++){
		if(gcd(i,j)==1&&i/j>=a/b&&i/j-a/b<=temp){
			temp=i/j-a/b;
			i1=i;
			j1=j;
		}
	}
	cout<<i1<<' '<<j1;
	return 0;
}
