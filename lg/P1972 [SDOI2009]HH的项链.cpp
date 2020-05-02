#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll n,m;
ll a[N],sum[N],vst[N],ans[N];
struct qry{ll l,r,id;} qs[N];
bool cmp(const qry &a,const qry &b){return a.r<b.r||a.r==b.r&&a.l<b.l;};
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
inline void update(ll p,ll a){for(;p<=n;p+=p&-p) sum[p]+=a;}
inline ll query(ll p){
	ll ans=0;
	for(;p;p-=p&-p) ans+=sum[p];
	return ans;
}
int main(){
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	m=read();
	for(ll i=1;i<=m;i++) qs[i]=(qry){read(),read(),i};
	sort(qs+1,qs+m+1,cmp);
	ll rt=0;
	for(ll i=1;i<=m;i++){
		while(rt<qs[i].r){
			rt++;
			if(vst[a[rt]])
				update(vst[a[rt]],-1);
			vst[a[rt]]=rt;
			update(rt,1);
		}
		ans[qs[i].id]=query(qs[i].r)-query(qs[i].l-1);
	}
	for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
