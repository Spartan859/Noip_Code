#include<bits/stdc++.h>
#define M 3005
#define N 2005
#define ll long long
using namespace std;
//每次dfs一个连通块，找环，如果环上的点数！=连通块内点数，则NO 
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
ll n,m;
//qxx
struct edge{ll v,nxt;}es[M];ll head[N],cnt;
inline void add_edge(ll u,ll v){es[++cnt]=(edge){v,head[u]};head[u]=cnt;}
ll ind[N],oud[N]; 
/*dfs
ll vst[N];
void dfs1(ll x){
	
}*/

int main(){
	//#ifndef ONLINE_JUDGE
	//freopen("A.in","r",stdin);
	//freopen("A.ans","w",stdout);
	//#endif
	while(cin>>n){
		m=read();
		//cout<<n<<' '<<m<<endl;
		//bool flag=1;
		for(ll i=1,u,v;i<=m;i++){
			u=read();v=read();
			oud[u]++;ind[v]++;
			//if(oud[u]==2||ind[v]==2) flag=0;
			add_edge(u,v);
		} 
		if(n>m){
			puts("NO");
			continue;
		}
		if(n==m){
			bool flag=1;
			for(ll i=1;i<=n;i++) if(ind[i]!=1||oud[i]!=1){
				flag=0;
				break;
			}
			if(flag) puts("YES");
			else puts("NO");
			continue;
		}
	}
	return 0;
} 
