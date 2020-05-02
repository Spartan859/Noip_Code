#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll T,n,m,cnt;
ll esx[N][N];
vector<ll> es[N];
ll vst[N],huan[N],dep[N],fa[N],chk[N][N];
void dfs(ll x,ll f){
	vst[x]=1;
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(ll i=0,y;i<es[x].size();i++){
		y=es[x][i];
		if(!vst[y]) dfs(y,x);
	}
}
inline bool check(){
	for(ll i=1;i<=cnt;i++){
		ll ccc=0;
		for(ll j=1;j<=cnt;j++) if(i!=j&&esx[huan[i]][huan[j]]) ++ccc;
		if(ccc!=2) return 0;
	}
	return 1;
} 
int main(){
	#ifdef ONLINE_JUDGE
	freopen("wish.in","r",stdin);
	freopen("wish.out","w",stdout);
	#endif
	scanf("%lld",&T);
	while(T--){
		memset(vst,0,sizeof(vst));
		memset(chk,0,sizeof(chk));
		bool flag=0;
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++) es[i].clear();
		memset(esx,0,sizeof(esx));
		
		for(ll i=1,u,v;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			if(u==v) continue;
			esx[u][v]=esx[v][u]=1;
			es[u].push_back(v);
			es[v].push_back(u);
		}
		dfs(1,0);
		for(ll i=1;i<=n;i++){
			for(ll j=0,y;j<es[i].size();j++){
				y=es[i][j];
				if(y!=fa[i]&&fa[y]!=i){
					cnt=0;
					ll tmpi=i,tmpy=y;
					if(chk[tmpi][tmpy]) continue;
					huan[++cnt]=tmpi;
					huan[++cnt]=tmpy;
					while(tmpi!=tmpy){
						if(dep[tmpi]>dep[tmpy]) tmpi=fa[tmpi],huan[++cnt]=tmpi;
						else tmpy=fa[tmpy],huan[++cnt]=tmpy;
					}
					--cnt;
					//for(ll i=1;i<=cnt;i++) cout<<huan[i]<<' ';
					//cout<<endl; 
					if(cnt>=4&&check()){
						flag=1;
						break;
					}else chk[i][y]=chk[y][i]=1;
				}
			}
			if(flag) break;
		}
		if(flag) cout<<"Wandan"<<endl;
		else cout<<"Kaopu"<<endl;
	}
	return 0;
}
