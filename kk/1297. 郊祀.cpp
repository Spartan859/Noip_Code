#include<bits/stdc++.h>
#define ll long long
#define ld long double 
#define N 310
using namespace std;
ll n; 
ll h[N],cnt[N];
ld f[N],tr[N][N],ans; 

inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("tradition.in","r",stdin);
	freopen("tradition.out","w",stdout);
	#endif
	n=read();
	f[0]=1.0;
	for(ll i=1;i<=n;i++) f[i]=f[i-1]*i;
	for(ll i=1;i<=n;i++) h[i]=read();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j&&h[j]>=h[i]) ++cnt[i];
	for(ll i=0;i<=n;i++) tr[i][0]=1.0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) tr[i][j]=tr[i-1][j-1]+tr[i-1][j];
		
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) 
			ans+=tr[n-1-cnt[i]][j-1]*f[j-1]*((n-j)*cnt[i]*f[n-j-1]+f[n-j])*j/f[n];
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0; 	
}
