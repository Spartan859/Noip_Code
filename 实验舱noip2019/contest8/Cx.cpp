#include<bits/stdc++.h>
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
ll f[N][N][N],dis[N][N];
multiset<ll> ms[N][N];
multiset<ll>::iterator it;
int main(){
	n=read();m=read();Q=read();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j) dis[i][j]=1e18;
	for(ll i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++)
				f[i][j][k]=dis[i][j];
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				if(!ms[i][k].empty()&&!ms[k][j].empty())
					f[i][j][k]=min(*ms[i][k].begin()+*ms[k][j].begin(),f[i][j][k]);
				ms[i][j].insert(f[i][j][k]);
			}
				
				
	for(ll i=1,x,y,z,tmp;i<=Q;i++){
		x=read();y=read();z=read();
		it=ms[y][z].find(f[y][z][x]);
		ms[y][z].erase(it);
		tmp=*ms[y][z].begin();
		if(tmp>=1e18) puts("-1");
		else printf("%lld\n",tmp);
		ms[y][z].insert(f[y][z][x]);
	}
	return 0;
}
