#include<iostream>
#include<cmath>
using namespace std;
int n,a,b,f[51];
int main(){
	cin>>n>>a>>b;
	a=min(a,b); b=max(a,b);
	for(int i=1;i<=n;i++){
		f[0]=1;
		if(i>=b) f[i]+=f[i-b];
		if(i>=a) f[i]+=f[i-a];
	}
	cout<<f[n];
	return 0;
}
