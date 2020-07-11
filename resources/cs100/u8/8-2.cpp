#include<iostream>
#define N 1005
using namespace std;
long long ans,n,i,j,f[N];
int main(){
	cin>>n;
	f[1]=1;
	for(i=2;i*2<=n;i+=2){
		f[i]=1;
		for(j=1;j*2<=i;j++) f[i]+=f[j];
		f[i+1]=f[i];
	}
	ans=1;
	for(j=1;j*2<=n;j++) ans+=f[j];
	cout<<ans;
	return 0;
}
