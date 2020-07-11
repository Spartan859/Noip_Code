#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1005;
ll n,m,W;
ll w[N],b[N];
ll id[N];
ll sW[N],sB[N];
ll f[N];
ll findfa(ll x){return id[x]==x?x:id[x]=findfa(id[x]);}
void unitefa(ll x,ll y){id[findfa(x)]=findfa(y);}
struct item{
	ll w,b;
};vector<item> g[N];
int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&W);
	for(ll i=1;i<=n;i++) scanf("%lld",w+i);
	for(ll i=1;i<=n;i++) scanf("%lld",b+i);
	for(ll i=1;i<=n;i++) id[i]=i;
	for(ll i=1,x,y;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		unitefa(x,y);
	}
	for(ll i=1;i<=n;i++) 
		g[findfa(i)].push_back((item){w[i],b[i]}),
		sW[findfa(i)]+=w[i],
		sB[findfa(i)]+=b[i];
	
	for(ll i=1;i<=n;i++) 
		if(id[i]==i) g[i].push_back((item){sW[i],sB[i]});
	for(ll i=1;i<=n;i++){
		if(id[i]==i)
			for(ll j=W;j>=0;j--){
				//f[j]=f[j-1];
				for(ll k=0;k<g[i].size();k++)
					if(g[i][k].w<=j)
						f[j]=max(f[j],f[j-g[i][k].w]+g[i][k].b);
			} 
		/*for(ll j=0;j<=W;j++) cout<<f[j]<<' ';
		cout<<endl;*/
	}
				
	printf("%lld\n",f[W]);
	return 0;
}

