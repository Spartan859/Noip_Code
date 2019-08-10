#include<bits/stdc++.h>
#define N 10005
#define M 20005
#define ll long long
using namespace std;
ll n,m;
vector<ll> es[N],w[N];
ll dis[N];

ll vst[N],inq[N];
bool spfa(ll x){
	inq[x]=1;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i],c=w[x][i];
		if(!vst[x]||dis[x]<dis[y]+c){
			if(inq[x]) return 0;
			dis[x]=dis[y]+c;
			vst[y]=1;
			if(!spfa(y)) return 0;
		}
	}
	inq[x]=0;
	return 1;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1,a,b,c,t;i<=m;i++){
		scanf("%lld",&t);
		if(t==3){
			scanf("%lld%lld",&a,&b);
			//cout<<1<<endl;
			es[a].push_back(b);
			w[a].push_back(0);
			es[b].push_back(a);
			w[b].push_back(0);
		} 
		if(t==1){
			scanf("%lld%lld%lld",&a,&b,&c);
			es[a].push_back(b);
			w[a].push_back(c);//反向边，正权 
		}
		if(t==2){
			scanf("%lld%lld%lld",&a,&b,&c);
			es[b].push_back(a);
			w[b].push_back(-c);
		}
	}
	for(ll i=1;i<=n;i++) es[n+1].push_back(i),w[n+1].push_back(0),es[i].push_back(0),w[i].push_back(0);
	//for(ll i=1;i<=n;i++) dis[i]=-2e18;
	bool flag=spfa(n+1);
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}
