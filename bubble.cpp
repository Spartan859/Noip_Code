#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,m;
ll bt[N];
ll p[N],tmp[N];
void add(ll i,ll x){
	while(i<=n+1){
		bt[i]+=x;
		i+=i&(-i);
	}
}
ll sum(ll i){
	ll rt=0;
	for(;i;i-=i&(-i)) rt+=bt[i];
	return rt;
}
int main(){
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&p[i]);	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=i-sum(p[i]+1)-1;
		add(p[i]+1,1);
	}
	for(ll i=1,t,c;i<=m;i++){
		scanf("%lld%lld",&t,&c);
		if(t==1){
			if(p[c]<p[c+1]) ans++;
			else if(p[c]>p[c+1]) ans--;
			swap(p[c],p[c+1]);
		}else{
			if(c>n){
				cout<<0<<endl;
				continue;
			}
			ll tmpans=ans;
			for(ll j=1;j<=n;j++) tmp[j]=p[j];
			for(ll j=1;j<=c;j++)
				for(ll a=1;a<=n-1;a++)
					if(tmp[a]>tmp[a+1]){
						swap(tmp[a],tmp[a+1]);
						tmpans--;
					}
			printf("%lld\n",tmpans);
		}
	}
	return 0;
}
