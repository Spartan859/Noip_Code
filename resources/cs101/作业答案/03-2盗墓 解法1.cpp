#include<iostream>
using namespace std;
int i,j,n,ans,f[101],x[101];
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i];
	f[0]=0; f[1]=x[1]; f[2]=x[2]; f[3]=x[3];
	for(i=4;i<=n;i++){
		int big=f[0];
		for(j=1;j<=i-3;j++) 
			big=max(big,f[j]);
		f[i]=max(f[i-1],big+x[i]);
	}
	ans=f[0];
	for(i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}


