#include<bits/stdc++.h>
#define N 500005
#define INF 2e18
#define ll long long
using namespace std;
ll n,m,id[N],cnt=1,w[N];
ll ans;
ll dpth[N];
ll sz[N];

ll findfa(ll x){
	if(x==id[x]){
		dpth[x]=1; 
		return x;
	}
	ll fa=findfa(id[x]);
	dpth[x]=dpth[id[x]]+1;
	return fa;
	//return x==id[x]?x:findfa(id[x]);//无路径压缩的findfa + 记录深度 
}

void unitefa(ll x,ll y,ll c){//纯净版按秩合并 
	ll fx=findfa(x),fy=findfa(y);
	if(fx==fy) return;
	if(sz[fx]>sz[fy]){
		id[fy]=fx;
		w[fy]=c;
		sz[fx]+=sz[fy];
	}else{
		id[fx]=fy;
		w[fx]=c;
		sz[fy]+=sz[fx];
	}
}

int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) id[i]=i,sz[i]=1;;
	for(ll i=1,t,u,v;i<=m;i++){
		scanf("%lld%lld%lld",&t,&u,&v);
		u^=ans;v^=ans;
		if(t==0){
			unitefa(u,v,cnt);
			cnt++;
		} else{
			ll fu=findfa(u),fv=findfa(v);
			if(fu!=fv){
				ans=0;
				printf("%lld\n",ans);
				continue;
			} 
			//lca找路径最小值
			ll uc=u,vc=v,ansm=0;
			while(uc!=vc){
				if(dpth[uc]>dpth[vc]) ansm=max(ansm,w[uc]),uc=id[uc];
				else ansm=max(ansm,w[vc]),vc=id[vc];
			}
			//cout<<endl;
			ans=ansm;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
