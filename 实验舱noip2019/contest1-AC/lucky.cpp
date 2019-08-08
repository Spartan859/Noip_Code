#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,q;
ll val[N];
vector<ll> es[N];
ll dpth[N],fax[N];
ll tmp[N],cnt;
void dfs(ll x,ll fa){//«Û…Ó∂»£¨fa 
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i];
		if(y==fa) continue;
		dpth[y]=dpth[x]+1;
		fax[y]=x;
		dfs(y,x);
	}
}
bool isfbx(ll a,ll b,ll c,ll d){
	if(a+b+c<=d) return 0;
	return 1;
}
int main(){
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++) scanf("%lld",val+i);
	for(ll i=1,u,v;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1,0);
	for(ll i=1,t,a,b;i<=q;i++){
		scanf("%lld%lld%lld",&t,&a,&b);
		if(t==0){
			cnt=0;
			while(a!=b&&cnt<50){
				if(dpth[a]>dpth[b]) tmp[++cnt]=val[a],a=fax[a];
				else tmp[++cnt]=val[b],b=fax[b];
			}
			tmp[++cnt]=val[a]; 
			if(cnt>=50){
				cout<<'Y'<<endl;
				continue;
			} 
			if(cnt<4){
				cout<<'N'<<endl;
				continue;
			}
			
			sort(tmp+1,tmp+cnt+1);
			bool ys=0;
			for(ll j=1;j<=cnt-3;j++){
				if(isfbx(tmp[j],tmp[j+1],tmp[j+2],tmp[j+3])){
					cout<<'Y'<<endl;
					ys=1;
					break;
				}
			}
			if(!ys){
				cout<<'N'<<endl;
			}
		}else val[a]=b;
	}
	//for(ll i=1;i<=n;i++) cout<<dpth[i]<<endl;
	return 0;
}
