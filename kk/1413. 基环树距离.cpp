#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
struct rtx{
	ll lca,rta,rtb;
};
ll n,rt,sum_loop,q;
struct qxx{
	ll to,w,nxt;
}es[N*2];
ll hd[N],num=-1;
ll vst[N],fa[N],fanew[N][20],dpth[N],sum[N],dst[N],res[N],shanb[N*2],vst2[N];
vector<pair<ll,ll> > loop;
inline void add_edge(ll a,ll b,ll c){
	es[++num]=(qxx){b,c,hd[a]};
	hd[a]=num;
}
bool findloop(ll u){
	vst[u]=1;
	bool rr=false;
	for(ll i=hd[u];i!=-1;i=es[i].nxt)
		if(i!=fa[u]){
			ll v=es[i].to;
			if(vst[v]==0){
				fa[v]=i^1;
				rr=(findloop(v)||rr);
			}else if(vst[v]==1){
				rt=v;
				rr=true;
				loop.push_back(make_pair(v,i^1));
			}
		}
	vst[u]=2;
	if(u==rt) rr=false;
	if(rr) loop.push_back(make_pair(u,fa[u]));
	return rr;
}
void dfs(ll x,ll f){
	vst2[x]=1;
	//cout<<x<<endl;
	fanew[x][0]=f;
	dpth[x]=dpth[f]+1;
	for(ll i=hd[x];i!=-1;i=es[i].nxt){
		if(shanb[i]) continue;
		ll y=es[i].to;
		if(vst2[y]) continue;
		if(y!=f){
			dst[y]=dst[x]+es[i].w;
			dfs(y,x);
		} 
	}
}
inline rtx lca(ll x,ll y){
	if(dpth[x]>dpth[y]) swap(x,y);
	for(ll i=17;i>=0;i--) 
		if(dpth[fanew[y][i]]>=dpth[x]) y=fanew[y][i];
	if(x==y) return (rtx){x,0,0};
	for(ll i=17;i>=0;i--)
		if(fanew[x][i]!=fanew[y][i]) x=fanew[x][i],y=fanew[y][i];
	return (rtx){fanew[x][0],x,y};
}
int main(){
	scanf("%lld",&n);
	for(ll i=0;i<=n;i++) hd[i]=-1;
	for(ll i=1,a,b,c;i<=n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	findloop(1);
	for(ll i=1;i<=n+1;i++) res[i]=-1;
	for(ll i=0;i<loop.size();i++){
		sum[i+1]=sum[i]+es[loop[i].second].w;
		sum_loop+=es[loop[i].second].w;
		res[loop[i].first]=i;
		shanb[loop[i].second]=shanb[loop[i].second^1]=1;
	}
	for(ll i=0;i<loop.size();i++){
		add_edge(n+1,loop[i].first,0);
		add_edge(loop[i].first,n+1,0);
	} 
	//cout<<"!!!!!!!!"<<endl;
	dfs(n+1,0);
	for(ll i=1;i<=17;i++)
		for(ll j=1;j<=n;j++) fanew[j][i]=fanew[fanew[j][i-1]][i-1];
	scanf("%lld",&q);
	for(ll i=1,a,b;i<=q;i++){
		scanf("%lld%lld",&a,&b);
		if(a==b){
			cout<<0<<endl;
			continue;
		} 
		rtx lx=lca(a,b);
		//cout<<lx.lca<<endl;
		if(lx.lca!=n+1){
			//cout<<dst[a]<<endl;
			cout<<dst[a]+dst[b]-dst[lx.lca]*2<<endl;
		} 
		else{
			ll tmp=0,st=res[lx.rta],ed=res[lx.rtb];
			//cout<<"de:"<<st<<' '<<ed<<endl;
			if(st>ed) swap(st,ed);
			tmp=min(sum[ed]-sum[st],sum_loop-sum[ed]+sum[st]);
			cout<<dst[a]+dst[b]+tmp<<endl;
		}
	}
	
	//cout<<"----debug----"<<endl;
	//for(ll i=1;i<=loop.size();i++) cout<<sum[i]<<' ';
	return 0;
}
