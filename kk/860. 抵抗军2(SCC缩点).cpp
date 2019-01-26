#include<bits/stdc++.h>
#define N 50005
#define ll long long
using namespace std;
//tarjan
ll n,m,u,v;//input data

vector<ll> es[N];
ll dfn[N],low[N],stk[N],instk[N],num,stktop,sccnum,scc[N];
ll chudu[N],rudu[N],ans1,ans2;
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
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		if(u!=v) es[u].push_back(v);
	}
	for(ll i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	//
	for(ll i=1;i<=n;i++)
		for(ll j=0,y;j<es[i].size();j++){
			y=es[i][j];
			if(scc[i]!=scc[y]){
				chudu[scc[i]]++,rudu[scc[y]]++;
				//cout<<i<<' '<<y<<' '<<scc[i]<<' '<<scc[y]<<endl;
			} 
		}
	
	for(ll i=1;i<=sccnum;i++){
		if(chudu[i]==0) ans1++;
		if(rudu[i]==0) ans2++;
	}
		
		
	if(sccnum==1) printf("%lld\n%lld\n",1,0);
	else printf("%lld\n%lld\n",ans2,max(ans1,ans2));
	return 0;
} 
