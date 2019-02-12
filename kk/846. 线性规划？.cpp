#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll dfn[N],low[N],stk[N],instk[N],c[N];
ll n,m,cnt,num,ans,top;
struct node{ll t,v;};
vector<node> es[N],ses[N];
struct SCC{ll sum,d,ind,tot;}scc[N];
inline void add(ll x,ll y,ll z){
	es[x].push_back((node){y,z});
}
void tarjan(ll x){
	dfn[x]=low[x]=++num;
	instk[x]=1;stk[++top]=x;
	for(ll i=0,y;i<es[x].size();i++){
		y=es[x][i].t;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(instk[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){
		cnt++;
		for(ll z;z!=x;){
			z=stk[top--];
			c[z]=cnt;
			instk[z]=0;
			scc[cnt].tot++;
		}
	}
}
void dfs(ll x){
	for(ll i=0;i<ses[x].size();i++){
		node e=ses[x][i];
		if(scc[x].d+e.v>scc[e.t].d){
			scc[e.t].d=scc[x].d+e.v;
			dfs(e.t);
		}
	}
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1,t,x,y;i<=m;i++){
		scanf("%lld %lld %lld",&t,&x,&y);
		if(t==1) add(x,y,0),add(y,x,0);
		if(t==2) add(x,y,1);
		if(t==3) add(y,x,0);
		if(t==4) add(y,x,1);
		if(t==5) add(x,y,0);
	}
	for(ll i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(ll i=1;i<=n;i++)
		for(ll j=0,y;j<es[i].size();j++){
			y=es[i][j].t;
			if(c[y]==c[i]) scc[c[i]].sum+=es[i][j].v;
			else{
				ses[c[i]].push_back((node){c[y],es[i][j].v});
				scc[c[y]].ind++;
			}
		}
	for(ll i=1;i<=cnt;i++)
		if(scc[i].sum>0){
			cout<<-1<<endl;
			return 0;
		}
	for(ll i=1;i<=cnt;i++) if(!scc[i].ind) scc[i].d=1,dfs(i);
	for(ll i=1;i<=cnt;i++) ans+=scc[i].d*scc[i].tot;
	printf("%lld\n",ans);
	return 0;
}
