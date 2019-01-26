#include<bits/stdc++.h>
#define N 505
#define ll long long
#define INF 10005
using namespace std;
ll a[N][N],n,ok[N],d[N],u,v;
void dj(){
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
	for(ll i=1;i<=n;i++) cout<<(d[i]!=INF?d[i]:-1)<<' ';
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)
	    for(ll j=1;j<=n;j++){
	    	cin>>a[i][j];
	    	if(a[i][j]==-1) a[i][j]=INF;
		}
	dj();
	return 0;
} 
