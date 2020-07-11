#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2505,INF=1e18;
const double ERR=1e-6;
ll k,n;
ll fa[N];
double w[N];
ll s[N],p[N];
vector<ll> es[N];
//0:超级源点 ，向所有根连边 
ll tim;
ll dfn[N],ed[N];
double f[N][N]; 
void dfs_dfn(ll x){
	dfn[x]=tim++;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		dfs_dfn(es[x][i]);
	}
	ed[dfn[x]]=tim;
}

bool OK(double m){//m=0.001 - 10000
	for(ll i=1;i<=n;i++) 
		w[dfn[i]]=p[i]-s[i]*m;//点权
	for(ll i=1;i<=n+1;i++)
		for(ll j=0;j<=k;j++) f[i][j]=-INF;
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=min(k,i);j++){
			f[ed[i]][j]=max(f[ed[i]][j],f[i][j]);
			//不选，直接跳到兄弟
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+w[i]);//把i点选上，并准备选儿子，或开始另一个兄弟
		}
	return f[n+1][k]>=ERR;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld%lld",&k,&n);++k; 
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&s[i],&p[i],&fa[i]);
		es[fa[i]].push_back(i);
	}
	dfs_dfn(0);
	double l=0.0,r=10000.0,mid;
	double ans;
	while(r-l>=ERR){
		double mid=(l+r)/2.0;
		if(OK(mid)) ans=mid,l=mid+ERR;
		else r=mid-ERR;
	}
	printf("%.3lf\n",ans);
	return 0;
}

