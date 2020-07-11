#include<bits/stdc++.h>
#define N 15
#define M 25
#define ll long long
#define INF 1e9
using namespace std;
ll n,m,k;
struct cd{
	ll h,r,s[N],dis[N][N],jd[N],cntjd,jdre[N];
}md[M];
vector<ll> cx[N];
ll tmpt=INF,vst[N];
ll ans;
inline ll proc(ll x,ll y,ll r){//在r环上，x环路位->y的距离 
	if(x<=y) return y-x;
	else return r-x+y;
}
void dfs(ll x,ll t){//目前在x号节点，已花去时间t 
	if(t>=tmpt) return;
	if(x==n+1){
		tmpt=min(tmpt,t);
		return;
	}
	//cout<<x<<' '<<t<<endl;
	vst[x]=1;
	for(ll i=0;i<cx[x].size();i++){
		ll lp=cx[x][i];//loop number
		ll tmptx=t+proc(t%md[lp].r+1,md[lp].jdre[x],md[lp].r);
		//if(x==0) cout<<t%md[lp].r+1<<' '<<md[lp].jdre[x]<<endl;
		for(ll j=1;j<=md[lp].cntjd;j++){
			ll to=md[lp].jd[j];
			if(vst[to]) continue;
			tmptx+=proc(md[lp].jdre[x],md[lp].jdre[to],md[lp].r);
			dfs(to,tmptx);
		}
	}
	vst[x]=0;
}
int main(){
	freopen("destiny.in","r",stdin);
	freopen("destiny.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld",&md[i].h,&md[i].r);
		for(ll j=1;j<=md[i].r;j++){
			scanf("%lld",&md[i].s[j]);
			if(md[i].s[j]==-1) md[i].s[j]=n+1;
		}
	}
	for(ll i=0;i<=n+1;i++){
		for(ll j=1;j<=m;j++){
			for(ll k=1;k<=md[j].r;k++) if(md[j].s[k]==i) cx[i].push_back(j);
		}
	}
	for(ll i=1;i<=m;i++){
		//确定交点 
		for(ll j=1;j<=md[i].r;j++){
			if(cx[md[i].s[j]].size()>1||md[i].s[j]==0||md[i].s[j]==n+1){
				md[i].jd[++md[i].cntjd]=md[i].s[j];
				md[i].jdre[md[i].s[j]]=j;
			}
		}
	}
	dfs(0,0);
	printf("%lld\n",tmpt);	
	return 0;
}
/*
2 2 1
1 3 0 1 2
1 3 1 2 -1
*/

