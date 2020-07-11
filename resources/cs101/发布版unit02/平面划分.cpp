#include<iostream>
using namespace std;
long long i,n,f[10001];
int main(){
	cin>>n;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=f[i-1]+i;
	cout<<f[n]<<endl;
	return 0;
}


