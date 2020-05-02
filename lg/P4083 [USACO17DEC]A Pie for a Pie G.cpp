#include<bits/stdc++.h>
#define INF 1e18
#define ll long long
using namespace std;
const ll maxn=100005;
//main
ll N,D;
struct pies{
	ll a,b,id;
}psa[maxn],psb[maxn];
bool cmp1(const pies &a,const pies &b){//a
	return a.a<b.a;
}
bool cmp2(const pies &a,const pies &b){
	return a.b<b.b;
}

ll dis[maxn*2],vst[maxn*2];//bfs
vector<ll> es[maxn*2];//build_graph
queue<ll> q;//find_end

void build_graph(){
	sort(psa+1,psa+N+1,cmp1);
	sort(psb+1,psb+N+1,cmp2);
	for(ll i=1;i<=N;i++){
		pies x=(pies){psa[i].b,psa[i].b,0};
		ll st=lower_bound(psb+1,psb+N+1,x,cmp2)-psb;
		//cout<<st<<endl;
		for(ll j=st;psb[j].b-x.b<=D&&j<=N;j++){
			es[psb[j].id].push_back(psa[i].id);
			//cout<<psa[i].id<<' '<<psb[j].id<<endl;
			//cout<<j<<endl;
		}
			
	}
	for(ll i=1;i<=N;i++){
		pies x=(pies){psb[i].a,psb[i].a,0};
		ll st=lower_bound(psa+1,psa+N+1,x,cmp1)-psa;
		//cout<<st<<endl;
		for(ll j=st;psa[j].a-x.a<=D&&j<=N;j++){
			es[psa[j].id].push_back(psb[i].id);
			//cout<<psb[j].b-x.b<<endl;
		}
			
	}
}
void bfs(){
	while(!q.empty()){
		ll u=q.front();q.pop();
		vst[u]=1;
		for(ll i=0;i<es[u].size();i++){
			ll v=es[u][i];
			if(vst[v]) continue;
			dis[v]=dis[u]+1;
			q.push(v);
			
		}	
	}
}
int main(){
	freopen("P4083_2.in","r",stdin);
	freopen("P4083_2.out1","w",stdout);
	scanf("%lld%lld",&N,&D);
	fill(dis+1,dis+N*2+1,-1);
	for(ll i=1;i<=N;i++){
		scanf("%lld%lld",&psa[i].a,&psa[i].b);
		psa[i].id=i;
		if(psa[i].b==0) q.push(i),dis[i]=1;
	}
	
	for(ll i=1;i<=N;i++){
		scanf("%lld%lld",&psb[i].a,&psb[i].b);
		psb[i].id=i+N;
		if(psb[i].a==0) q.push(i+N),dis[i+N]=1;
	}
	
	
	build_graph();
	bfs();
	
	for(ll i=1;i<=N;i++) printf("%lld\n",dis[i]);
	return 0;
}
/*
2 1
1 1
5 0
4 2
1 4
*/

