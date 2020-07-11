#include<iostream>
using namespace std;
long long i,n,ans,f[101],x[101];
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i];
	f[0]=0; f[1]=x[1]; f[2]=x[2];
	for(i=3;i<=n;i++)
		f[i]=max(f[i-2],f[i-3])+x[i];
	ans=max(f[n],f[n-1]);
	cout<<ans<<endl;
	return 0;
}


