#include<iostream>
using namespace std;
long long i,n,f[51];
int main(){
	cin>>n;
	f[0]=f[1]=1; 
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	cout<<f[n]<<endl;
	return 0;
}


