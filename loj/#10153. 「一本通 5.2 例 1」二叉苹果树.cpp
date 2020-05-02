#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
using namespace std;
const ll N=105;
ll n,q;
ll sza[N];//apple 
ll szs[N];//size edge
ll wei[N];//点权 
ll f[N][N],sons[N][2];
struct dat{ll to,w;};
vector<dat> es[N];

void dfsdq(ll x,ll fa){
	if(es[x].size()==1){
		szs[x]=0;//叶节点，设子枝和为0，回溯 
		sza[x]=0;
		return;
	}  
	for(ll i=0,cntmp=0;i<es[x].size();i++){
		ll y=es[x][i].to,wx=es[x][i].w;
		//cout<<"dex "<<wx<<endl;
		if(y==fa) continue;
		wei[y]=wx;//边权转点权。
		dfsdq(y,x); 
		sza[x]+=sza[y];
		szs[x]+=szs[y];
		sons[x][cntmp++]=y;
	}
	sza[x]+=wei[sons[x][0]]+wei[sons[x][1]];
	szs[x]+=2;
}

void dfsdp(ll x,ll fa){
	if(es[x].size()==1) return;
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i].to;
		if(y==fa) continue;
		dfsdp(y,x);
	}
	//转移
	ll lson=sons[x][0],rson=sons[x][1];
	for(ll j=1;j<=szs[x];j++){
		if(j-1<=szs[lson]) f[x][j]=max(f[x][j],f[lson][j-1]+wei[lson]);
		if(j-1<=szs[rson]) f[x][j]=max(f[x][j],f[rson][j-1]+wei[rson]);
	} 
	 
	for(ll j=0;j<=szs[x]-2;j++)
		for(ll k=max(0,j-szs[rson]);k<=min(lson,j);k++)
			f[x][j+2]=max(f[x][j+2],max(f[x][j],f[lson][k]+f[rson][j-k]+wei[lson]+wei[rson]));
}
int main(){
	freopen("C:/Users/Spartan117/Desktop/P2015_4.in","r",stdin);
	scanf("%lld%lld",&n,&q);
	for(ll i=1,u,v,w;i<=n-1;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		es[u].push_back((dat){v,w});
		es[v].push_back((dat){u,w});
	} 
	dfsdq(1,0);
	dfsdp(1,0);
	printf("%lld\n",f[1][q]);
	//debug1();
	//cout<<szs[1]<<endl;
	return 0;
}
/*
删一侧的讨论出锅s 
*/

