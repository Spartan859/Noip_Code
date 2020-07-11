#include<iostream>
using namespace std;
long long i,n,f[51];
int main(){
	cin>>n;
	f[0]=1; 
	for(i=1;i<=n;i++){
		f[i]=0;
		if(i>=1) f[i]+=f[i-1];
		if(i>=2) f[i]+=f[i-2];
	}
	cout<<f[n]<<endl;
	return 0;
}


