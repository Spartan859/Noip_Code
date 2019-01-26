#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
ll a[N],d[N],sum[N],n,p,x,y,z,ans,x1,y11;
int main(){
	cin>>n>>p;
	for(ll i=1;i<=n+1;i++){
		a[i]=1;
		d[i]=a[i]-a[i-1];
	} 
	for(ll i=1;i<=p;i++){
		cin>>x1>>y11;
		if(x1<=y11) x=x1,y=y11;
		else y=x1,x=y11;
		x++;y++;
		d[x]-=1;
		d[y+1]+=1;
	}
	for(ll i=1;i<=n+1;i++){
		sum[i]=d[i]+sum[i-1];
		ans+=(sum[i]>0);
	}
	cout<<ans<<endl;
	return 0;
}
