#include<bits/stdc++.h>
#define bzmax 20
#define N 2005
#define ll long long
using namespace std;
int n;
int ans;
vector<ll> es[N];
int bz[N][25],in[N],out[N],dep[N],cnt;
int a[N];
int lcax[N][N];
void dfs(int p, int fa) {
	dep[p]=dep[fa]+1;
	//cout<<p<<' '<<fa<<endl;
   bz[p][0] = fa, in[p] = ++cnt;
   for (int i = 1; i < bzmax; i++)
       bz[p][i] = bz[bz[p][i - 1]][i - 1];
   for (int i = 0; i<es[p].size(); i ++) {
        int e = es[p][i];
       if (e == fa) continue;
       dfs(e, p);
   }
    out[p] = cnt;
}

int lca(int a, int b) {
    if (dep[a] > dep[b])    swap(a, b);
    if (in[a] <= in[b] && out[a] >= out[b])
        return a;
    for (int i = bzmax - 1, nx; ~i; i--) {
        nx = bz[a][i];
        if (!(in[nx] <= in[b] && out[nx] >= out[b]))
           a = nx;
    }
    return bz[a][0];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		for(int j=2,ds;j<=n;j++){
			ll t1=i,t2=j;
			if(a[t1]>a[t2]) swap(t1,t2);
			if(!lcax[t1][t2]) lcax[t1][t2]=lca(t1,t2);
			ds=dep[t1]+dep[t2]-2*dep[lcax[t1][t2]];
			ans=max(ans,a[t2]*ds);
		}
	cout<<ans<<endl;
	return 0;
}

