#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl
#define N 205
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
ll n,m,Q;
ll f[N][N],dis[N][N];
multiset<ll> ms[N][N];
multiset<ll>::iterator it;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	n=read();m=read();Q=read();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j) dis[i][j]=1e18;
	for(ll i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
				
				
	for(ll q=1,x,y,z,tmp;q<=Q;q++){
		x=read();y=read();z=read();
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++) f[i][j]=dis[i][j];
		for(ll k=1;k<=n;k++)
			for(ll i=1;i<=n;i++)
				for(ll j=1;j<=n;j++){
					//f[i][j]=dis[i][j];
					if(k!=x) f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
		if(f[y][z]>=1e18) puts("-1");
		else printf("%lld\n",tmp);
	}
	return 0;
}
