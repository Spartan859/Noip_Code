#include<iostream>
using namespace std;
long long i,n,f[51];
int main(){
	cin>>n;
	f[0]=0;
	for(i=1;i<=n;i++)
		f[i]=f[i-1]*2+1;
	cout<<f[n]<<endl;
	return 0;
}


