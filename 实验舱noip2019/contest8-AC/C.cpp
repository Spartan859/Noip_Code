#include<bits/stdc++.h>
#define N 205
#define Q_MAX 100005
#define INF 1e18
#define ll long long
using namespace std;
ll n,m,Q;
ll dis[N][N];
struct queryx{
	ll id,u,v;
};
vector<queryx> q[N];
ll ans[Q_MAX];
void fenzhi(ll l,ll r){//从l到r之间的k进行松弛 
	if(l==r) {
		for(ll i=0;i<q[l].size();i++){
			ll u=q[l][i].u,v=q[l][i].v,id=q[l][i].id;
			if(dis[u][v]<INF) ans[id]=dis[u][v];
			else ans[id]=-1;
		}
		return;
    }
    ll f[N][N];memcpy(f,dis,sizeof(dis));//f 临时记录dis在处理左半区间之前的值 
	ll mid=(l+r)>>1;
    for(ll i=l;i<=mid;i++)
		for(ll j=1;j<=n;j++)
	    	for(ll k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    fenzhi(mid+1,r);
    memcpy(dis,f,sizeof(dis));
    for(ll i=mid+1;i<=r;i++)
		for(ll j=1;j<=n;j++)
	    	for(ll k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    fenzhi(l,mid);
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&Q);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) if(i!=j) dis[i][j]=INF;
	for(ll i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(ll i=1,x,y,z;i<=Q;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		q[x].push_back((queryx){i,y,z});
	}
	fenzhi(1,n);
	for(ll i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
} 
