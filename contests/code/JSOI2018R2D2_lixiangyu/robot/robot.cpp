#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
#define N 6
using namespace std;
ll n,m,ans,T;
ll vst[N][N],cnt;
ll mp[N][N];
struct route{
	ll x,y;
}rtx[N*N];
void dfs(ll x,ll y){
	rtx[++cnt]=(route){x,y};
	if(cnt==n*m){
		if(!((x+1>n?1:x+1)==1&&y==1||x==1&&(y+1>m?1:y+1)==1)){
			--cnt;
			return;
		}
		for(ll i=1;i<=n*m;i++)
			if(mp[rtx[i].x][rtx[i].y]){
				ans=(ans+i-1)%MOD;
				break;
			} 
		--cnt;
		return;
	}
	vst[x][y]=1;
	if(!vst[x+1>n?1:x+1][y]) dfs(x+1>n?1:x+1,y);
	if(!vst[x][y+1>m?1:y+1]) dfs(x,y+1>m?1:y+1);
	vst[x][y]=0;
	--cnt;
}

int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0,cnt=0;
		memset(mp,0,sizeof(mp));
		scanf("%lld%lld",&n,&m);
		char ch;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++){
				cin>>ch;
				if(ch=='0') mp[i][j]=0;
				else mp[i][j]=1;
			}
		dfs(1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
