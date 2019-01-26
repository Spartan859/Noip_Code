#include<bits/stdc++.h>
#define N 105
#define K 505
#define ll long long
#define INF 1000005
using namespace std;
struct edge{
	ll v,d,c;
};
struct point{
	ll dis,cost,id;
	const bool operator < (const point &a) const{
		return dis>a.dis;
	}
}cur;
ll n,ok[N],d[N][K],u,v,m,k,u1,v1,d1,c1;
vector<edge> es[10010];
priority_queue<point> q;
void dj(){
	ll ans=INF;
	for(ll i=1;i<=n;i++)
	    for(ll j=0;j<=k;j++) d[i][j]=INF;
	d[1][0]=0;
	for(q.push((point){0,0,1});!q.empty();){
		cur=q.top(); q.pop(); ll u=cur.id;
		if(cur.dis>d[u][cur.cost]) continue;
		for(ll i=0,v,cost;i<es[u].size();i++){
			cost=es[cur.id][i].c+cur.cost;
			if(es[cur.id][i].c+cur.cost>k) continue;
			if(cur.dis+es[cur.id][i].d<d[es[cur.id][i].v][cur.cost+es[cur.id][i].c]){
				d[es[cur.id][i].v][cur.cost+es[cur.id][i].c]=d[cur.id][cur.cost]+es[cur.id][i].d;
				q.push((point){d[es[cur.id][i].v][cur.cost+es[cur.id][i].c],cur.cost+es[cur.id][i].c,es[cur.id][i].v});
			}
		}
	}
	for(int i=0;i<=k;i++) ans=min(ans,d[n][i]);
	cout<<(ans==INF?-1:ans)<<endl; 
}
int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u1>>v1>>d1>>c1;
		if(u1!=v1) es[u1].push_back((edge){v1,d1,c1});
	}
	dj();
	return 0;
} 
