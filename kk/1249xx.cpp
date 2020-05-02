#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll ch[N*50][2],a[N];
ll tot,n,ans,pre;
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}

inline void insert(ll x){
    ll u=0;
    for(ll k=60;k>=0;k--){
        ll c=(x>>k)&1;
        if(!ch[u][c]) ch[u][c]=++tot;
        u=ch[u][c];
    }
}
inline ll query(ll x){
    ll u=0,v=0,ans=0;
    for(ll k=60;k>=0;k--){
        ll c=(x>>k)&1,o=c?0:1;
        if(ch[v][o]) v=ch[v][o],ans=(ans<<1)|1;
        else v=ch[v][c],ans<<=1;
        u=ch[u][c];
    }
	return ans;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	#endif
    n=read();
    insert(0);
    for(ll i=1;i<=n;i++){
    	a[i]=read();
    	pre^=a[i];
    	ans=max(ans,query(pre));
		insert(pre);
	}
    printf("%lld\n",ans);
	return 0;
}
