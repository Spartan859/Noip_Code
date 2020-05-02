#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110000;

ll n,m,T;
ll a[N],sum[N],id[N],k,cadt[N],bw[N];
vector<ll> es1[N],es2[N];
struct edgest{
	ll u,v;
}estmp[N];ll cntp;

void dfsltk(ll x,ll c){
	id[x]=c;sum[c]+=a[x];
	for(ll i=0;i<es1[x].size();i++){
		ll to=es1[x][i];
		if(!id[to]) dfsltk(to,c);
	}
}

bool dfsbw(ll x,ll c,bool &t,ll &sb,ll &sw){
	if(~bw[x]) return bw[x]==c;
	bw[x]=c;t|=cadt[x];
	if(c==0) sb+=sum[x];
	else sw+=sum[x];
	bool rt=1;
	for(ll i=0;i<es2[x].size();i++){
		rt&=dfsbw(es2[x][i],c^1,t,sb,sw);
	}
	return rt;
}
int main(){
	//freopen("P6185_1.in","r",stdin);
	scanf("%lld",&T);
	while(T--){
		cntp=0;memset(id,0,sizeof(id));k=0;
		memset(sum,0,sizeof(sum));
		memset(cadt,0,sizeof(cadt));
		
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++) scanf("%lld",a+i);
		
		for(ll i=1,tmp;i<=n;i++){
			scanf("%lld",&tmp);
			a[i]=tmp-a[i];
			es1[i].clear();es2[i].clear();
		} 
		
		for(ll i=1,t,u,v;i<=m;i++){
			scanf("%lld%lld%lld",&t,&u,&v);
			if(t==1) estmp[++cntp]=(edgest){u,v};
			else es1[u].push_back(v),es1[v].push_back(u);
		}
		for(ll i=1;i<=n;i++)
			if(!id[i]) dfsltk(i,++k);
		for(ll i=1,u,v;i<=cntp;i++){
			u=estmp[i].u;
			v=estmp[i].v;
			if(id[u]==id[v]) cadt[id[u]]=1;
			else{
				es2[id[u]].push_back(id[v]);
				es2[id[v]].push_back(id[u]);
			}
		}
		memset(bw,-1,sizeof(bw));
		bool ans=1;
		for(ll i=1;i<=k;i++){
			if(bw[i]==-1){
				bool tg=0;
				ll sumb=0,sumw=0;
				if(dfsbw(i,0,tg,sumb,sumw))
					if(tg) ans&=(sumb+sumw)%2==0;
					else ans&=sumb==sumw;
				else ans&=(sumb+sumw)%2==0;
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}
