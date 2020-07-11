#include<iostream>
using namespace std;
int i,n,ans,f[1001],x[1001];
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i];
	f[1]=x[1]; 
	for(i=2;i<=n;i++){
		int tmp=0;
		if(i>2) tmp=max(tmp,f[i-2]);
		if(i>3) tmp=max(tmp,f[i-3]);
		f[i]=tmp+x[i];
	}
	ans=f[1];
	for(i=2;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}


