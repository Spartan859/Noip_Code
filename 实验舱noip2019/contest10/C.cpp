#include<bits/stdc++.h>
#define N 1000005
#define BS 131
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct fax{ll id;char c;};
ll n,m,Q;
fax triefa[N];
//ll trie[N][11];
char S[N];ll hsh[N],bsx[N];

inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
inline ll rhsh(ll l,ll r){
	return (hsh[r]-hsh[l-1]*bsx[r-l+1]%mod+mod)%mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	n=read();m=read();Q=read();
	bsx[0]=1;
	for(ll i=1;i<=m;i++) bsx[i]=bsx[i-1]*BS%mod;
	for(ll i=1;i<=n-1;i++){
		triefa[i].id=read();
		triefa[i].c=getchar();
	}
	scanf("%s",&S);
	for(ll i=1;i<=m;i++) hsh[i]=(hsh[i-1]*BS%mod+S[i-1])%mod;
	//for(ll i=1;i<=m;i++) cout<<hsh[i]<<endl;
	for(ll i=1,x,l,r,cx,hshx,nowbs,ans;i<=Q;i++){
		x=read();l=read();r=read();
		cx=x;hshx=0;nowbs=0;
		while(cx) hshx+=triefa[cx].c*bsx[nowbs]%mod,hshx%=mod,cx=triefa[cx].id,nowbs++;
		//cout<<hshx<<' '<<nowbs<<endl;
		ans=0;
		for(ll lk=l,rk=l+nowbs-1;rk<=r;lk++,rk++) if(rhsh(lk,rk)==hshx) ans++;
		printf("%lld\n",ans);
	}
	return 0;
} 
