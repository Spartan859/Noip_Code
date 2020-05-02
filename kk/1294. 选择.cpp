#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
const ll inf=2e18;
ll n,p[N],pre[N],mn[N]={inf},ans;
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	#endif
	n=read();
	for(ll i=1;i<=n;i++) p[i]=read(),pre[i]=pre[i-1]^p[i],mn[i]=min(mn[i-1],pre[i]);
	//ans=p[1];
	//for(ll i=2;i<=n;i++) ans=max(max(ans,pre[i]^mn[i-1]),pre[i]);
	for(ll i=1;i<=n;i++)
		for(ll j=i;j<=n;j++){
			if(i==j) ans=max(ans,p[i]);
			else ans=max(ans,pre[j]^pre[i-1]);
		}
	printf("%lld\n",ans);
	return 0;
} 
