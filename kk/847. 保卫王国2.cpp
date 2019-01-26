#include<bits/stdc++.h>
#define N 10000
#define ll long long
using namespace std;
ll n,m,T;//input data

vector<ll> es[N*2+10];
ll dfn[N*2+10],low[N*2+10],stk[N*2+10],instk[N*2+10],num,stktop,sccnum,scc[N*2+10];
void tarjan(ll x){
	dfn[x]=low[x]=++num;
	stk[++stktop]=x;instk[x]=1;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(instk[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){//new scc
		sccnum++;
		for(;stk[stktop]!=x;stktop--){
			scc[stk[stktop]]=sccnum;instk[stk[stktop]]=0;
		}
		scc[stk[stktop]]=sccnum;instk[stk[stktop]]=0;stktop--;
	}
}
inline void clear_all(){
	for(ll i=1;i<=N*2;i++) es[i].clear();
	fill(dfn,dfn+N*2+1,0);
	fill(low,low+N*2+1,0);
	stktop=0;
	sccnum=0;
	fill(instk,instk+N*2+1,0);
	fill(scc,scc+N*2+1,0);
}
int main(){
	scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		clear_all();
		scanf("%lld %lld",&n,&m);
		for(ll i=1,a,va,b,vb;i<=m;i++){
			scanf("%lld %lld %lld %lld",&a,&va,&b,&vb);
			es[a+n*(va&1)].push_back(b+n*(vb^1));
			es[b+n*(vb&1)].push_back(a+n*(va^1));
		}
		for(ll i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
		ll ix;
		for(ix=1;ix<=n;ix++)
			if(scc[ix]==scc[ix+n]){
				printf("IMPOSSIBLE\n");
				break;
			}
		if(ix==n+1) printf("POSSIBLE\n");
	}
	return 0;
}
