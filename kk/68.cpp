#include<bits/stdc++.h>
#define ll long long
#define N 500009
using namespace std;
ll a[N],d[N],sum[N],n,p,x,y,z,ans,x1,y11;
int main(){
	cin>>n>>p;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	} 
	for(ll i=1;i<=p;i++){
		cin>>x1>>y11>>z;
		if(x1<=y11) x=x1,y=y11;
		else y=x1,x=y11;
		d[x]+=z;
		d[y+1]-=z;
	}
	for(ll i=1;i<=n;i++) sum[i]=d[i]+sum[i-1];
	ans=*min_element(sum+1,sum+n+1);
	cout<<ans<<endl;
	return 0;
}
