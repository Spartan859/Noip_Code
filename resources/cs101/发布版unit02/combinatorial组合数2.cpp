#include<iostream>
using namespace std;
long long f(int x){
	long long ans=1;
	for(int i=2;i<=x;i++)
		ans*=i;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<f(n)/f(m)/f(n-m); 
	return 0;
}
