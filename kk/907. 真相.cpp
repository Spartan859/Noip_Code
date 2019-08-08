#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m,t[N],x[N],y[N];
ll ulp[N];//ulp[i]=1:i is useless
ll tis1[N],cnt;
vector<ll> es[N];ll ind[N];//邻接表和入度 
ll cnt2;//记录杀掉的点的个数 
//ll bhzt[N];//b[i]==2 safe b[i]==1 no protection b[i]==0 dead
ll thtmk[N],cnt3,thtmk2[N],cnt4,ans;//这一轮要杀掉的点集，总数，轮番维护暂时变量
ll tmp; 

ll id[N];//并查集 
ll findfa(ll x){
	return x==id[x]?x:id[x]=findfa(id[x]);
}
void unite(ll x,ll y){
	id[findfa(x)]=findfa(y);
}
inline ll rtrt(ll x){
	if(ans%2==0) return thtmk[x];
	else return thtmk2[x];
}

int main(){
	//freopen("truth.in","r",stdin);
	//freopen("truth.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) id[i]=i;
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",t+i,x+i,y+i);
		if(t[i]==0) unite(x[i],y[i]);
		if(t[i]==1) tis1[++cnt]=i;
	}
	for(ll i=1;i<=n;i++) if(i!=findfa(i)) ulp[i]=1;
	for(ll k=1;k<=cnt;k++){
		ll i=tis1[k];
		es[findfa(x[i])].push_back(findfa(y[i]));
		ind[findfa(y[i])]++;
	}
	//缩点完成
	cnt3=0;
	for(ll i=1;i<=n;i++){
		if(ind[i]==0&&!ulp[i]) thtmk[++cnt3]=i;
	}
	while(cnt2<n){
		tmp=cnt2;
		if(ans%2==0) cnt4=0;
		else cnt3=0;
		for(ll i=1;i<=(ans%2==0?cnt3:cnt4);i++){
			cnt2++;
			for(ll j=0;j<es[rtrt(i)].size();j++){
				--ind[es[rtrt(i)][j]];
				cout<<es[rtrt(i)][j]<<endl;
				if(ind[es[rtrt(i)][j]]==0) if(ans%2==0) thtmk2[++cnt4]=es[i][j]; else thtmk[++cnt3]=es[i][j];
			}
		}
		if(tmp==cnt2){
			puts("diediedie");
			return 0;
		}
		
		//
		//cout<<"ans="<<ans<<' ';
		//for(ll i=1;i<=(ans%2==0?cnt3:cnt4);i++) cout<<(ans%2==0?thtmk[i]:thtmk2[i])<<' ';
		//cout<<endl;
		//
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
