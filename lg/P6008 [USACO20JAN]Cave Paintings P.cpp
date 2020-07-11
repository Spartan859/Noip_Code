#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1005,MOD=1e9+7;
ll n,m;
ll mp[N][N];
ll tot,ans=1;
ll nxt[3][2]={{1,0},{0,-1},{0,1}};//ÏÂ£¬×ó£¬ÓÒ 
//ll cnt[N*N];
ll id[N*N],wsx[N*N],vst[N*N];
string s;
//ll nw;
/*inline void calc(ll x){
	++cnt[x];
	if(cnt[x]==1) ++nw;
}*/
ll findfa(ll x){return x==id[x]?x:id[x]=findfa(id[x]);}
inline void unitefa(ll x,ll y){
	ll fx=findfa(x),fy=findfa(y);
	id[fx]=fy;
	wsx[fy]=wsx[fy]*wsx[fx]%MOD;
}
inline ll ksm(ll x,ll y){
	ll rt=1;
	while(y){
		if(y&1) rt=rt*x%MOD;
		x=x*x%MOD;y>>=1;
	}
	return rt;
}
int main(){
	//freopen("tst.in","r",stdin); 
	scanf("%lld%lld",&n,&m);
	//cout<<ksm(n,m)<<endl;
	for(ll i=1;i<=1000005;i++) id[i]=i,wsx[i]=1;
	for(ll i=1;i<=n;i++){
		cin>>s;s=' '+s;
		for(ll j=1;j<=m;j++){
			if(s[j]=='#') mp[i][j]=-2;
			else mp[i][j]=++tot;
		} 
	}
	for(ll i=n;i>=1;i--){
		for(ll j=1;j<=m;j++){
			if(mp[i][j]==-2) continue;
			for(ll k=0;k<3;k++){
				ll nx=i+nxt[k][0],ny=j+nxt[k][1];
				if(mp[nx][ny]==-2) continue;
				if(findfa(mp[nx][ny])!=findfa(mp[i][j])) unitefa(mp[nx][ny],mp[i][j]);
			} 
		}
		for(ll j=1;j<=m;j++) 
			if(mp[i][j]>0&&!vst[findfa(mp[i][j])]) ++wsx[findfa(mp[i][j])],vst[findfa(mp[i][j])]=1;
		//clr
		memset(vst,0,sizeof(vst));
	}
		
	/*for(ll i=1;i<=n;i++,cout<<endl)
		for(ll j=1;j<=m;j++)
			if(mp[i][j]==-2) cout<<'#'<<' ';
			else cout<<mp[i][j]<<' '; 
	cout<<findfa(1)<<endl;*/
	for(ll i=1;i<=1000000;i++) if(id[i]==i) ans=ans*wsx[i]%MOD;
	printf("%lld\n",ans);
	return 0;
}

