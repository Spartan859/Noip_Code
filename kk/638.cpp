#include<bits/stdc++.h>
#define N 2005
#define ll long long
#define INF 10005
using namespace std;
ll a[N][N],n,ok[N],d[N],u,v;
void dj(){
	ll ans=0;
	fill(d,d+n+2,INF);
	d[1]=0;
	for(ll i=1;i<=n;i++){
		u=n+1;
		for(ll v=1;v<=n;v++)
		    if(!ok[v]&&d[v]<d[u]) u=v;
		ok[u]=1;
		for(ll v=1;v<=n;v++)
		    d[v]=min(d[v],d[u]+a[u][v]);
	}
	for(ll i=1;i<=n;i++) ans+=d[i];
	cout<<ans<<endl;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)
	    for(ll j=1;j<=n;j++){
	    	if(i!=j) a[i][j]=(j*666+i*i)%233;
	    	else a[i][j]=INF;
		}
	dj();
	return 0;
}
