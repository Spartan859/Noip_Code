#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
const ll MOD=1e9+7; 
ll n,ans=1;
bool prime[N];
inline ll read(){
	ll res=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}
inline void getp(){
	prime[0]=prime[1]=0;
	for(ll i=2;i<=n;i++)
		if(prime[i])
			for(ll j=i*i;j<=n;j+=i)
				prime[j]=0;
}
ll ppp(ll n,ll p){return n>=p?n/p+ppp(n/p,p):0;}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	#endif
	n=read();
	memset(prime,1,sizeof(prime));
    getp();
    for(ll i=2;i<=n;i++)
    	if(prime[i]) ans=ans*(ppp(n,i)*2+1)%MOD;
    printf("%lld\n",ans);
    //cout<<prime[5]<<endl;
    return 0;
}
