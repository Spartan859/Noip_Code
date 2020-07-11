#include<iostream>
using namespace std;
long long i,n,a,b,f[51];
int main(){
	cin>>n>>a>>b;
	f[0]=1;
	for(i=1;i<=n;i++){
		f[i]=0;
		if(i>=a) f[i]+=f[i-a];
		if(i>=b) f[i]+=f[i-b];
	}
	cout<<f[n]<<endl;
	return 0;
}


