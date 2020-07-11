#include<bits/stdc++.h>
#define N 3000005
#define ll long long
using namespace std;
ll n;
ll cnt[N];
ll ans;
priority_queue<ll> q;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
int main(){
	n=read();
	for(ll i=1,tmp;i<=n;i++){
		tmp=read();
		++cnt[tmp];
	}
	for(ll i=1;i<=n;i++) if(cnt[i]>0) q.push(cnt[i]);
	ll x,y,z;
	while(q.size()>=3){
		x=q.top();q.pop();
		y=q.top();q.pop();
		z=q.top();q.pop();
		ll mn=min(x,min(y,z));
		ans+=mn;x-=mn;y-=mn;z-=mn;
		if(x>0) q.push(x);
		if(y>0) q.push(y);
		if(z>0) q.push(z);
	}
	printf("%lld\n",ans);
	return 0;
}

