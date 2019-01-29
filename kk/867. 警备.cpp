#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,u,v,w,vst[3005][3005],tmp,ans,bpf;
struct edge{
	ll t,w;
};
vector<edge> es[N];

int main(){
	freopen("guardance.in","r",stdin);
	freopen("guardance.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n-1;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		es[u].push_back((edge){v,w});
		es[v].push_back((edge){u,w});
		vst[u][v]=vst[v][u]=1;
		if(w!=1) bpf=1;
	}
	if(!bpf){
		cout<<n*(n-1)-n-n+2<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			if(j!=i&&!vst[i][j]){
				tmp=0;
				for(ll k=0;k<es[j].size();k++) tmp=max(tmp,es[j][k].w);
				ans+=tmp+1;
				vst[i][j]=vst[j][i]=1;
			}
		}
	cout<<ans-1<<endl;
	return 0;
}
