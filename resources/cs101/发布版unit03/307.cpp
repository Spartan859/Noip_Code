#include<iostream>
using namespace std;
int main(){
	int n,m,ans;
	cin>>n>>m;
	int co[n+1],f[n+1];
	for(int i=1;i<=n;i++) cin>>co[i];
	f[1]=co[1];
	//input end
	for(int i=2;i<=n;i++){
		int big=0;
		if(i>m-1) big=max(f[i-m+1],big);
		if(i>m) big=max(f[i-m],big);
		if(i>m+1) big=max(f[i-m-1],big);
		f[i]=big+co[i];
	}
	ans=f[1];
	for(int i=2;i<=n;i++)
	    ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}
